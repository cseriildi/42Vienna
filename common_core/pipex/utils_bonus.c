/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:55:32 by icseri            #+#    #+#             */
/*   Updated: 2024/05/27 18:25:57 by icseri           ###   ########.fr       */
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

	data->i_fd = open(data->infile, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (data->i_fd == -1)
		elegant_exit(data, CANNOT_OPEN_FILE);
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
		ft_putstr_fd(line, data->i_fd);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(data->i_fd);
}
