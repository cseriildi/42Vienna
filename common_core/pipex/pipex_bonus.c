/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:19 by icseri            #+#    #+#             */
/*   Updated: 2024/05/29 18:46:06 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(t_var *data)
{
	safe_close(data->pipe[0]);
	if (data->is_here_doc == true)
		here_doc(data);
	else
		data->i_fd = safe_open(data->infile, 'R', data);
	if (dup2(data->i_fd, STDIN_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	safe_close(data->i_fd);
	delete_file(data);
	if (dup2(data->pipe[1], STDOUT_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	safe_close(data->pipe[1]);
	exec_command(data, 0);
}

void	middle_command(t_var *data, int cmd_index)
{
	create_process(data, data->pipe2);
	if (data->pid == 0)
	{
		safe_close(data->pipe2[0]);
		safe_close(data->pipe[1]);
		if (dup2(data->pipe[0], STDIN_FILENO) == -1)
			elegant_exit(data, DUP2_FAIL);
		safe_close(data->pipe[0]);
		if (dup2(data->pipe2[1], STDOUT_FILENO) == -1)
			elegant_exit(data, DUP2_FAIL);
		safe_close(data->pipe2[1]);
		exec_command(data, cmd_index);
	}
	else
	{
		safe_close(data->pipe[0]);
		safe_close(data->pipe[1]);
		data->pipe[0] = data->pipe2[0];
		data->pipe[1] = data->pipe2[1];
	}
}

void	last_command(t_var *data)
{
	if (data->is_here_doc == true && access(data->outfile, F_OK) == 0)
		data->o_fd = safe_open(data->outfile, 'A', data);
	else
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
	int		i;

	if (argc < 5 || (ft_strncmp(argv[1], "here_doc", 9) == 0 && argc < 6))
	{
		ft_putendl_fd(error_message(ERROR_MISUSE), STDERR_FILENO);
		exit (ERROR_MISUSE);
	}
	data = malloc(sizeof(t_var));
	if (!data)
		elegant_exit(NULL, MALLOC_FAIL);
	parse_input(data, argc, argv, env);
	create_process(data, data->pipe);
	if (data->pid == 0)
		first_command(data);
	else
	{
		waitpid(data->pid, NULL, 0);
		i = 0;
		while (data->pid > 0 && ++i < data->cmd_count - 1)
			middle_command(data, i);
		if (i == data->cmd_count - 1 && data->pid > 0)
			last_command(data);
	}
}
