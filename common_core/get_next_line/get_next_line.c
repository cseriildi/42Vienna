/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:27:07 by icseri            #+#    #+#             */
/*   Updated: 2024/04/18 18:24:29 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*unused_chars;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!unused_chars)
		unused_chars = read_file(fd, unused_chars);
	if (!unused_chars)
		return (NULL);
	if (!unused_chars[0])
		return (free(unused_chars), NULL);
	line = line_search(unused_chars);
	tmp = remove_line(unused_chars, line);
	free(unused_chars);
	unused_chars = tmp;
	if (!unused_chars)
		free(unused_chars);
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
	printf("[%s]\n", line);
	close(fd);
}
 */