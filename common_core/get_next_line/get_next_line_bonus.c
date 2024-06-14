/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:27:07 by icseri            #+#    #+#             */
/*   Updated: 2024/06/14 13:47:40 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*read_chars[1024];
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	read_chars[fd] = read_fd(fd, read_chars[fd]);
	if (!read_chars[fd])
		return (ft_free(&read_chars[fd]), NULL);
	line = line_search(read_chars[fd]);
	if (!line || !*line)
		return (ft_free(&read_chars[fd]), ft_free(&line), NULL);
	tmp = ft_strjoin(NULL, read_chars[fd] + ft_strlen(line));
	ft_free(&read_chars[fd]);
	read_chars[fd] = tmp;
	if (!read_chars[fd])
		return (ft_free(&line), ft_free(&read_chars[fd]), NULL);
	return (line);
}

/* int	main(void)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*line2;

	fd = open("test.txt", O_RDWR);
	if (fd == -1)
		return (-1);
	fd2 = open("test.txt", O_RDWR);
	if (fd2 == -1)
		return (-1);
	line = get_next_line(fd);
	line2 = get_next_line(fd2);
	while (line || line2)
	{
		if (line)
		{
			printf("[%s]\n", line);
			free(line);
			line = get_next_line(fd);
		}
		if (line2)
		{
			printf("[%s]\n", line2);
			free(line2);
			line2 = get_next_line(fd2);
		}
	}
	close(fd);
}
 */