/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:19 by icseri            #+#    #+#             */
/*   Updated: 2024/05/22 21:34:31 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(char *cmd, char **env)
{
	char	**path;
	char	**args;
	char	*tmp;
	char	*full_path;
	int		i;

	i = 0;
	args = ft_split(cmd, ' ');
	if (!args)
		exit(2);
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	path = ft_split(env[i] + 5, ':');
	if (!path)
	{
		array_free(&args);
		exit(3);
	}
	i = 0;
	while (path[i] && *args)
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
		{
			array_free(&path);
			array_free(&args);
			exit(4);
		}
		full_path = ft_strjoin(tmp, args[0]);
		if (!full_path)
		{
			array_free(&path);
			array_free(&args);
			free(tmp);
			exit(4);
		}
		free(tmp);
		execve(full_path, args, env);
		free(full_path);
		i++;
	}
	array_free(&args);
	array_free(&path);
	perror("Command does not exist\n");
	exit(1);
}

void	first_command(int *pipe_fd, char *infile, char *cmd, char **env)
{
	int	fd;

	fd = open(infile, O_RDONLY, 0777);
	if (fd == -1)
	{
		perror("Could not open file\n");
		exit(1);
	}
	close(pipe_fd[0]);
	if (dup2(fd, STDIN_FILENO) == -1)
		exit(1);
	close(fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		exit(1);
	close(pipe_fd[1]);
	exec_command(cmd, env);
}

void	last_command(int *pipe_fd, char *outfile, char *cmd, char **env)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("Could not open/create outfile");
		exit(1);
	}
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		exit(1);
	close(pipe_fd[0]);
	if (dup2(fd, STDOUT_FILENO) == -1)
		exit(1);
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
		return (perror("Could not open pipe\n"), 1);
	pid = fork();
	if (pid == -1)
	{
		perror("Error occured while forking\n");
		return (close(pipe_fd[0]), close(pipe_fd[1]), 1);
	}
	else if (pid == 0)
		first_command(pipe_fd, argv[1], argv[2], env);
	else
	{
		wait(NULL);
		last_command(pipe_fd, argv[argc - 1], argv[argc - 2], env);
	}
	return (0);
}
