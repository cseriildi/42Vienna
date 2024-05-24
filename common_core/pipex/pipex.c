/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:19 by icseri            #+#    #+#             */
/*   Updated: 2024/05/24 13:51:56 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_path(t_var *data)
{
	int		i;

	while (data->env[i] && ft_strncmp(data->env[i], "PATH=", 5) != 0)
		i++;
	if (!data->env[i])
		elegant_exit("PATH not found", NULL, NULL);
	data->path = ft_split(data->env[i] + 5, ':');
	if (!data->path)
		elegant_exit("Memory allocation failed", NULL, NULL);
}

char	*find_path(t_var *data, int cmd_index)
{
	int		i;
	char	*abs_cmd;

	i = -1;
	while (data->path[++i])
	{
		abs_cmd = ft_strjoin2(data->path[i], data->commands[cmd_index], "/");
		if (!abs_cmd)
			elegant_exit("Memory allocation failed", data->path, NULL);
		if (access(abs_cmd, F_OK | X_OK) == 0)
			return (abs_cmd);
		free(abs_cmd);
	}
	elegant_exit("Command does not exist", data->path, NULL);
}

void	set_command(t_var *data, int cmd_index)
{
	data->args = ft_split(data->commands[cmd_index], ' ');
	if (!data->args)
		elegant_exit("Memory allocation failed", NULL, NULL);
	data->cmd = data->args[0];
	if (access(data->cmd, F_OK | X_OK) == 0)
		data->absolut_cmd = data->cmd;
	else
		data->absolut_cmd = find_path(data, cmd_index);
}

void	first_command(t_var *data)
{
	data->infile_fd = open(data->infile, O_RDONLY, 0777);
	if (data->infile_fd == -1)
		elegant_exit("Could not open file", NULL, NULL);
	close(data->pipe_fd[0]);
	if (dup2(data->infile_fd, STDIN_FILENO) == -1)
		elegant_exit("Error while dup2", NULL, NULL);
	close(data->infile_fd);
	if (dup2(data->pipe_fd[1], STDOUT_FILENO) == -1)
		elegant_exit("Error while dup2", NULL, NULL);
	close(data->pipe_fd[1]);
	set_command(data, 0);
	execve(data->absolut_cmd, data->args, data->env);
}

void	last_command(t_var *data)
{
	data->outfile_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->outfile_fd == -1)
		elegant_exit("Could not open/create outfile", NULL, NULL);
	close(data->pipe_fd[1]);
	if (dup2(data->pipe_fd[0], STDIN_FILENO) == -1)
		elegant_exit("Error while dup2", NULL, NULL);
	close(data->pipe_fd[0]);
	if (dup2(data->outfile_fd, STDOUT_FILENO) == -1)
		elegant_exit("Error while dup2", NULL, NULL);
	close(data->outfile_fd);
	set_command(data, data->cmd_count - 1);
	execve(data->absolut_cmd, data->args, data->env);
}

void	parse_input(t_var *data, int count, char **params, char **env)
{
	int	i;

	data->env = env;
	set_path(data);
	data->infile = params[1];
	data->outfile = params[count - 1];
	data->cmd_count = count - 3;
	i = -1;
	while (++i < data->cmd_count)
		data->commands[i] = params[i + 2];
	data->commands[i] = NULL;
}

int	main(int argc, char **argv, char **env)
{
	t_var *data;

	if (argc != 5)
	{
		ft_putendl_fd("Number of parameters are incorrect", STDERR_FILENO);
		return (1);
	}
	parse_input(data, argc, argv, env);
	if (pipe(data->pipe_fd) == -1)
		elegant_exit("Could not open pipe", NULL, NULL);
	data->pid = fork();
	if (data->pid == -1)
	{
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
		elegant_exit("Error occured while forking", NULL, NULL);
	}
	else if (data->pid == 0)
		first_command(data);
	else
	{
		wait(0);
		last_command(data);
	}
	return (0);
}
