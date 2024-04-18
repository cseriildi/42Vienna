/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:27:07 by icseri            #+#    #+#             */
/*   Updated: 2024/04/18 11:46:28 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*unused_chars;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	unused_chars = read_file(fd, unused_chars);
	if (!unused_chars || !unused_chars[0])
		return (free(unused_chars), NULL);
	line = line_search(unused_chars);
	unused_chars = ft_strchr(unused_chars, '\n');
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
	while (line)
	{
		printf("[%s]\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
 */