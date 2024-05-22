/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:19 by icseri            #+#    #+#             */
/*   Updated: 2024/05/22 23:24:02 by cseriildii       ###   ########.fr       */
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
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
	{
		perror("PATH not found");
		exit(EXIT_FAILURE);
	}
	path = ft_split(env[i] + 5, ':');
	if (!path)
		exit(EXIT_FAILURE);
	args = ft_split(cmd, ' ');
	if (!args)
	{
		array_free(&path);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (path[++i] && *args)
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
		{
			array_free(&path);
			array_free(&args);
			exit(EXIT_FAILURE);
		}
		full_path = ft_strjoin(tmp, args[0]);
		free(tmp);
		if (!full_path)
		{
			array_free(&path);
			array_free(&args);
			exit(EXIT_FAILURE);
		}
		execve(full_path, args, env);
		free(full_path);
	}
	array_free(&args);
	array_free(&path);
	perror("Command does not exist");
	exit(EXIT_FAILURE);
}

void	first_command(int *pipe_fd, char *infile, char *cmd, char **env)
{
	int	fd;

	fd = open(infile, O_RDONLY, 0777);
	if (fd == -1)
	{
		perror("Could not open file");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("Error while dup2");
		exit(EXIT_FAILURE);
	}
	close(fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("Error while dup2");
		exit(EXIT_FAILURE);
	}
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
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
	{
		perror("Error while dup2");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("Error while dup2");
		exit(EXIT_FAILURE);
	}
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
		return (perror("Could not open pipe"), 1);
	pid = fork();
	if (pid == -1)
	{
		perror("Error occured while forking");
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
