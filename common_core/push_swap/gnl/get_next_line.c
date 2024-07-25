/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:27:07 by icseri            #+#    #+#             */
/*   Updated: 2024/07/18 12:59:16 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

static char	*read_fd(int fd, char *read_chars)
{
	char		*tmp;
	char		*buffer;
	long		read_size;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (ft_free(&read_chars), NULL);
	read_size = 1;
	while (read_size > 0 && is_nl(read_chars) == 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (ft_free(&buffer), ft_free(&read_chars), NULL);
		buffer[read_size] = '\0';
		tmp = ft_strjoin(read_chars, buffer);
		ft_free(&read_chars);
		read_chars = tmp;
		if (!read_chars)
			return (ft_free(&buffer), ft_free(&read_chars), NULL);
	}
	ft_free(&buffer);
	if (!read_chars || !read_chars[0])
		return (ft_free(&read_chars), NULL);
	return (read_chars);
}

char	*get_next_line(int fd)
{
	static char	*read_chars;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(read_chars), NULL);
	read_chars = read_fd(fd, read_chars);
	if (!read_chars)
		return (ft_free(&read_chars), NULL);
	line = line_search(read_chars);
	if (!line || !*line)
		return (ft_free(&read_chars), ft_free(&line), NULL);
	tmp = ft_strjoin(NULL, read_chars + ft_strlen(line));
	ft_free(&read_chars);
	read_chars = tmp;
	if (!read_chars)
		return (ft_free(&line), ft_free(&read_chars), NULL);
	return (line);
}
