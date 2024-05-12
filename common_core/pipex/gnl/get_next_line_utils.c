/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:27:19 by icseri            #+#    #+#             */
/*   Updated: 2024/05/06 10:51:40 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_nl(char *read_chars)
{
	while (read_chars && *read_chars)
	{
		if (*read_chars == '\n')
			return (1);
		read_chars++;
	}
	return (0);
}

char	*line_search(char *read_chars)
{
	char	*line;
	int		len;

	if (!read_chars)
		return (NULL);
	len = 0;
	while (read_chars[len] && read_chars[len] != '\n')
		len++;
	if (read_chars[len] == '\n')
		len++;
	if (len == 0)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (--len >= 0)
		line[len] = read_chars[len];
	return (line);
}
