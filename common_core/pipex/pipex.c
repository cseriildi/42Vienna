/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:19 by icseri            #+#    #+#             */
/*   Updated: 2024/05/27 18:48:46 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(t_var *data)
{
	data->i_fd = open(data->infile, O_RDONLY, 0777);
	if (data->i_fd == -1)
		elegant_exit(data, CANNOT_OPEN_FILE);
	close(data->pipe_fd[0]);
	if (dup2(data->i_fd, STDIN_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	close(data->i_fd);
	if (dup2(data->pipe_fd[1], STDOUT_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	close(data->pipe_fd[1]);
	exec_command(data, 0);
}

void	last_command(t_var *data)
{
	data->o_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->o_fd == -1)
		elegant_exit(data, CANNOT_OPEN_FILE);
	close(data->pipe_fd[1]);
	if (dup2(data->pipe_fd[0], STDIN_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	close(data->pipe_fd[0]);
	if (dup2(data->o_fd, STDOUT_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	close(data->o_fd);
	exec_command(data, data->cmd_count - 1);
}

int	main(int argc, char **argv, char **env)
{
	t_var	*data;

	if (argc != 5)
		elegant_exit(NULL, ERROR_MISUSE);
	data = malloc(sizeof(t_var));
	if (!data)
		elegant_exit(NULL, MALLOC_FAIL);
	parse_input(data, argc, argv, env);
	if (pipe(data->pipe_fd) == -1)
		elegant_exit(data, PIPE_FAIL);
	data->pid = fork();
	if (data->pid == -1)
		elegant_exit(data, FORK_FAIL);
	else if (data->pid == 0)
		first_command(data);
	else
		last_command(data);
	return (0);
}
