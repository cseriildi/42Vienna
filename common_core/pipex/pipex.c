/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:19 by icseri            #+#    #+#             */
/*   Updated: 2024/06/27 09:32:44 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(t_var *data)
{
	data->i_fd = safe_open(data->infile, 'R', data);
	safe_close(data->pipe[0]);
	if (dup2(data->i_fd, STDIN_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	safe_close(data->i_fd);
	if (dup2(data->pipe[1], STDOUT_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	safe_close(data->pipe[1]);
	exec_command(data, 0);
}

void	last_command(t_var *data)
{
	data->o_fd = safe_open(data->outfile, 'C', data);
	safe_close(data->pipe[1]);
	if (dup2(data->pipe[0], STDIN_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	safe_close(data->pipe[0]);
	if (dup2(data->o_fd, STDOUT_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	safe_close(data->o_fd);
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
	create_process(data, data->pipe);
	if (data->pid == 0)
		first_command(data);
	data->last_pid = fork();
	if (data->last_pid == -1)
		elegant_exit(data, FORK_FAIL);
	else if (data->last_pid == 0)
		last_command(data);
	safe_close(data->pipe[0]);
	safe_close(data->pipe[1]);
	while (wait(&data->exit_status) > 0)
		continue ;
	waitpid(data->last_pid, &data->exit_status, 0);
	if (WIFEXITED(data->exit_status))
		data->exit_code = WEXITSTATUS(data->exit_status);
	free_and_exit(data, data->exit_code);
}
