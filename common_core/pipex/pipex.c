/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:19 by icseri            #+#    #+#             */
/*   Updated: 2024/05/24 18:18:29 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(t_var *data)
{
	data->infile_fd = open(data->infile, O_RDONLY, 0777);
	if (data->infile_fd == -1)
		elegant_exit("Could not open file", data);
	close(data->pipe_fd[0]);
	if (dup2(data->infile_fd, STDIN_FILENO) == -1)
		elegant_exit("Error while dup2", data);
	close(data->infile_fd);
	if (dup2(data->pipe_fd[1], STDOUT_FILENO) == -1)
		elegant_exit("Error while dup2", data);
	close(data->pipe_fd[1]);
	set_command(data, 0);
	execve(data->absolut_cmd, data->args, data->env);
}

void	last_command(t_var *data)
{
	data->outfile_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->outfile_fd == -1)
		elegant_exit("Could not open/create outfile", data);
	close(data->pipe_fd[1]);
	if (dup2(data->pipe_fd[0], STDIN_FILENO) == -1)
		elegant_exit("Error while dup2", data);
	close(data->pipe_fd[0]);
	if (dup2(data->outfile_fd, STDOUT_FILENO) == -1)
		elegant_exit("Error while dup2", data);
	close(data->outfile_fd);
	set_command(data, data->cmd_count - 1);
	execve(data->absolut_cmd, data->args, data->env);
}

int	main(int argc, char **argv, char **env)
{
	t_var	*data;

	if (argc != 5)
	{
		ft_putendl_fd("Number of parameters are incorrect", STDERR_FILENO);
		return (1);
	}
	data = malloc(sizeof(t_var));
	if (!data)
		elegant_exit("Memory allocation failed", data);
	parse_input(data, argc, argv, env);
	if (pipe(data->pipe_fd) == -1)
		elegant_exit("Could not open pipe", data);
	data->pid = fork();
	if (data->pid == -1)
		elegant_exit("Error occured while forking", data);
	else if (data->pid == 0)
		first_command(data);
	else
	{
		wait(0);
		last_command(data);
	}
	return (0);
}
