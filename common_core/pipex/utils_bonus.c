/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:55:32 by icseri            #+#    #+#             */
/*   Updated: 2024/05/29 18:40:21 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	delete_file(t_var *data)
{
	if (data->is_here_doc == true)
	{
		if (access(data->infile, F_OK) == -1)
			elegant_exit(data, UNLINK_FAIL);
		if (unlink(data->infile) == -1)
			elegant_exit(data, UNLINK_FAIL);
	}
}

void	generate_random_filename(t_var *data)
{
	int	rand_fd;

	rand_fd = safe_open("/dev/urandom", 'R', data);
	if (read(rand_fd, data->infile, 10) != 10)
	{
		safe_close(rand_fd);
		perror("Cannot read from /dev/urandom");
		exit(EXIT_FAILURE);
	}
	safe_close(rand_fd);
}

void	here_doc(t_var *data)
{
	char	*line;
	int		fd;

	generate_random_filename(data);
	fd = safe_open(data->infile, 'C', data);
	data->i_fd = safe_open(data->infile, 'R', data);
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, data->limiter, ft_strlen(data->limiter) + 1) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	safe_close(fd);
}
