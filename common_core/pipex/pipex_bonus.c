/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:19 by icseri            #+#    #+#             */
/*   Updated: 2024/05/29 11:41:41 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(t_var *data)
{
	if (pipe(data->pipe) == -1)
		elegant_exit(data, PIPE_FAIL);
	data->pid = fork();
	if (data->pid == -1)
		elegant_exit(data, FORK_FAIL);
	else if (data->pid == 0)
	{
		close(data->pipe[0]);
		if (data->is_here_doc == false)
		{
			data->i_fd = open(data->infile, O_RDONLY, 0777);
			if (data->i_fd == -1)
				elegant_exit(data, CANNOT_OPEN_FILE);
		}
		if (dup2(data->i_fd, STDIN_FILENO) == -1)
			elegant_exit(data, DUP2_FAIL);
		close(data->i_fd);
		if (dup2(data->pipe[1], STDOUT_FILENO) == -1)
			elegant_exit(data, DUP2_FAIL);
		close(data->pipe[1]);
		exec_command(data, 0);
	}
/* 	else if (data->is_here_doc == false)
		waitpid(data->pid, NULL, 0); */

}

void	middle_command(t_var *data, int cmd_index)
{
	if (pipe(data->pipe2) == -1)
		elegant_exit(data, PIPE_FAIL);
	data->pid = fork();
	if (data->pid == -1)
		elegant_exit(data, FORK_FAIL);
	else if (data->pid == 0)
	{
		close(data->pipe2[0]);
		close(data->pipe[1]);
		if (dup2(data->pipe[0], STDIN_FILENO) == -1)
			elegant_exit(data, DUP2_FAIL);
		close(data->pipe[0]);
		if (dup2(data->pipe2[1], STDOUT_FILENO) == -1)
			elegant_exit(data, DUP2_FAIL);
		close(data->pipe2[1]);	
		exec_command(data, cmd_index);
	}
	else
	{
		close(data->pipe[0]);
		close(data->pipe[1]);
		data->pipe[0] = data->pipe2[0];
		data->pipe[1] = data->pipe2[1];
	}
}

void	last_command(t_var *data)
{
	if (data->is_here_doc == true && access(data->outfile, F_OK) == 0)
		data->o_fd = open(data->outfile, O_WRONLY | O_APPEND, 0777);
	else
		data->o_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->o_fd == -1)
		elegant_exit(data, CANNOT_OPEN_FILE);
	close(data->pipe[1]);
	if (dup2(data->pipe[0], STDIN_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	close(data->pipe[0]);
	if (dup2(data->o_fd, STDOUT_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	close(data->o_fd);
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
	if (data->is_here_doc == true)
		here_doc(data);
	if (data->pid != 0)
		first_command(data);
	i = 0;
	while (data->pid > 0 && ++i < data->cmd_count - 1)
		middle_command(data, i);
	if (i == data->cmd_count - 1 && data->pid > 0)
		last_command(data);
}