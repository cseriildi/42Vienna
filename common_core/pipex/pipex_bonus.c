/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:19 by icseri            #+#    #+#             */
/*   Updated: 2024/05/27 15:45:50 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(t_var *data, int cmd_index)
{
	data->args = ft_split(data->commands[cmd_index], ' ');
	if (!data->args)
		elegant_exit(data, MALLOC_FAIL);
	data->cmd = data->args[0];
	if (access(data->cmd, F_OK) == 0)
		data->absolut_cmd = data->cmd;
	else
		data->absolut_cmd = find_path(data);
	if (execve(data->absolut_cmd, data->args, data->env) == -1)
	{
		if (data->absolut_cmd == NULL)
			elegant_exit(data, COMMAND_NOT_FOUND);
		else
			elegant_exit(data, ERROR_CANNOT_EXECUTE);
	}
}

void	delete_file(t_var *data)
{
	if (access(data->infile, F_OK) == -1)
		elegant_exit(data, UNLINK_FAIL);
	if (unlink(data->infile) == -1)
		elegant_exit(data, UNLINK_FAIL);
}

void here_doc(t_var *data)
{
    char *line;

	data->infile_fd = open(data->infile, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (data->infile_fd == -1)
		elegant_exit(data, CANNOT_OPEN_FILE);
	ft_putstr_fd("pipe heredoc> ", STDOUT_FILENO);
	line = get_next_line(STDIN_FILENO);
	while (line)
    {
		if (ft_strncmp(line, ft_strjoin(data->limiter, "\n"), ft_strlen(data->limiter) + 2) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd("pipe heredoc> ", STDOUT_FILENO);
		ft_putstr_fd(line, data->infile_fd);
        free(line);
		line = get_next_line(STDIN_FILENO);
    }
	close(data->infile_fd);
}

void	first_command(t_var *data)
{
	if (ft_strncmp(data->infile, "here_doc", 9) == 0)
		here_doc(data);
	data->infile_fd = open(data->infile, O_RDONLY, 0777);
	if (data->infile_fd == -1)
		elegant_exit(data, CANNOT_OPEN_FILE);
	if (dup2(data->infile_fd, STDIN_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	close(data->infile_fd);
	delete_file(data);
	close(data->pipe_fd[0]);
	if (dup2(data->pipe_fd[1], STDOUT_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	close(data->pipe_fd[1]);
	exec_command(data, 0);
}

//void	middle_commands(t_var *data)

void	last_command(t_var *data)
{
	if (ft_strncmp(data->infile, "here_doc", 9) == 0
		&& access(data->outfile, F_OK) == 0)
		data->outfile_fd = open(data->outfile, O_WRONLY | O_APPEND, 0777);
	else
		data->outfile_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->outfile_fd == -1)
		elegant_exit(data, CANNOT_OPEN_FILE);
	close(data->pipe_fd[1]);
	if (dup2(data->pipe_fd[0], STDIN_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	close(data->pipe_fd[0]);
	if (dup2(data->outfile_fd, STDOUT_FILENO) == -1)
		elegant_exit(data, DUP2_FAIL);
	close(data->outfile_fd);
	exec_command(data, data->cmd_count - 1);
}

int	main(int argc, char **argv, char **env)
{
	t_var	*data;

	if (argc < 5 || (ft_strncmp(argv[1], "here_doc", 9) == 0 && argc < 6))
	{
		ft_putendl_fd(error_message(ERROR_MISUSE), STDERR_FILENO);
		exit (ERROR_MISUSE);
	}
	data = malloc(sizeof(t_var));
	if (!data)
		elegant_exit(data, MALLOC_FAIL);
	parse_input(data, argc, argv, env);
	if (pipe(data->pipe_fd) == -1)
		elegant_exit(data, PIPE_FAIL);
	if (pipe(data->here_doc_fd) == -1)
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
