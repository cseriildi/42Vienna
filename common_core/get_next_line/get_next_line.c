/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:27:07 by icseri            #+#    #+#             */
/*   Updated: 2024/04/19 16:47:30 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*read_chars;
	char		*line;
	char		*tmp;
	char		*buffer;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (is_nl(read_chars) == 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (free(buffer),free(read_chars), NULL);
		if (read_size == 0)
			break ;
		buffer[read_size] = '\0';
		tmp = ft_strjoin(read_chars, buffer);
		free(read_chars);
		read_chars = tmp;
	}
	free(buffer);
	if (!read_chars || !read_chars[0])
		return (free(read_chars), NULL);
	line = line_search(read_chars);
 	read_chars = remove_line(read_chars);
	return (line);
}
/* 
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDWR);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	printf("[%s]\n", line);
	free(line);
	line = get_next_line(fd);
	printf("[%s]\n", line);
	free(line);
	close(fd);
	fd = open("test.txt", O_RDWR);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		printf("[%s]\n", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("[%s]\n", line);
	close(fd);
}
 */