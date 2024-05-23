/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:19 by icseri            #+#    #+#             */
/*   Updated: 2024/05/23 18:13:48 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_path(t_cmd *command, char **env)
{
	char	**path;
	int		i;

	while (*env && ft_strncmp(*env, "PATH=", 5) != 0)
		env++;
	if (!*env)
		elegant_exit("PATH not found", NULL, NULL);
	path = ft_split(*env + 5, ':');
	if (!path)
		elegant_exit("Memory allocation failed", NULL, NULL);
	i = -1;
	while (path[++i])
	{
		command->path = ft_strjoin_with_delimiter(path[i], command->cmd, "/");
		if (!command->path)
			elegant_exit("Memory allocation failed", path, NULL);
		if (access(command->path, F_OK) == 0)
		{
			array_free(&path);
			return ;
		}
		free(command->path);
	}
	elegant_exit("Command does not exist", command->args, NULL);
}

void	exec_command(char *cmd, char **env)
{
	t_cmd	*command;

	command = malloc(sizeof(t_cmd));
	if (!command)
		elegant_exit("Memory allocation failed", NULL, NULL);
	command->args = ft_split(cmd, ' ');
	command->cmd = command->args[0];
	if (!command->args)
		elegant_exit("Memory allocation failed", NULL, NULL);
	set_path(command, env);
	execve(command->path, command->args, env);
	free(command->path);
	elegant_exit("Command could not be executed", command->args, NULL);
}

void	first_command(int *pipe_fd, char *infile, char *cmd, char **env)
{
	int	fd;

	fd = open(infile, O_RDONLY, 0777);
	if (fd == -1)
		elegant_exit("Could not open file", NULL, NULL);
	close(pipe_fd[0]);
	if (dup2(fd, STDIN_FILENO) == -1)
		elegant_exit("Error while dup2", NULL, NULL);
	close(fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		elegant_exit("Error while dup2", NULL, NULL);
	close(pipe_fd[1]);
	exec_command(cmd, env);
}

void	last_command(int *pipe_fd, char *outfile, char *cmd, char **env)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		elegant_exit("Could not open/create outfile", NULL, NULL);
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		elegant_exit("Error while dup2", NULL, NULL);
	close(pipe_fd[0]);
	if (dup2(fd, STDOUT_FILENO) == -1)
		elegant_exit("Error while dup2", NULL, NULL);
	close(fd);
	exec_command(cmd, env);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (argc != 5)
	{
		ft_putendl_fd("Number of parameters are incorrect", STDERR_FILENO);
		return (1);
	}
	if (pipe(pipe_fd) == -1)
		elegant_exit("Could not open pipe", NULL, NULL);
	pid = fork();
	if (pid == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		elegant_exit("Error occured while forking", NULL, NULL);
	}
	else if (pid == 0)
		first_command(pipe_fd, argv[1], argv[2], env);
	else
	{
		wait(0);
		last_command(pipe_fd, argv[argc - 1], argv[argc - 2], env);
	}
	return (0);
}
