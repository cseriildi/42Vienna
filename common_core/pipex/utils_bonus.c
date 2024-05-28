/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:55:32 by icseri            #+#    #+#             */
/*   Updated: 2024/05/28 15:25:14 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	delete_file(t_var *data)
{
	if (ft_strncmp(data->infile, "here_doc", 9) == 0)
	{
		if (access(data->infile, F_OK) == -1)
			elegant_exit(data, UNLINK_FAIL);
		if (unlink(data->infile) == -1)
			elegant_exit(data, UNLINK_FAIL);
	}
}

void	here_doc(t_var *data)
{
	char	*line;

	if (pipe(data->here_doc_pipe) == -1)
		elegant_exit(data, PIPE_FAIL);
	data->pid = fork();
	if (data->pid == -1)
		elegant_exit(data, FORK_FAIL);
	else if (data->pid == 0)
	{
		printf("%s\n", "here_doc");
		close(data->here_doc_pipe[0]);
		ft_putstr_fd("pipe heredoc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		while (line)
		{
			if (ft_strncmp(line, data->limiter, ft_strlen(data->limiter) + 1) == 0)
			{
				free(line);
				break ;
			}
			ft_putstr_fd("pipe heredoc> ", STDOUT_FILENO);
			ft_putstr_fd(line, data->here_doc_pipe[1]);
			free(line);
			line = get_next_line(STDIN_FILENO);
		}
		close(data->here_doc_pipe[1]);
		exit(EXIT_SUCCESS);
	}
}
