/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:27:19 by icseri            #+#    #+#             */
/*   Updated: 2024/04/18 18:23:57 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	int		i;
	int		j;
	int		len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = 0;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	joined_str = malloc(len + 1);
	if (joined_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		joined_str[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		joined_str[i++] = s2[j++];
	joined_str[i] = '\0';
	return (joined_str);
}

char	*remove_line(char *unused_chars, char *line)
{
	char	*trimmed;
	int		i;
	int		j;

	if (!unused_chars || !line)
		return (NULL);
	j = ft_strlen(line);
	trimmed = malloc(ft_strlen(unused_chars) - j + 1);
	if (trimmed == NULL)
		return (NULL);
	i = 0;
	while (unused_chars[j])
		trimmed[i++] = unused_chars[j++];
	trimmed[i] = '\0';
	return (trimmed);
}

char	*line_search(char *s)
{
	char	*line;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *unused_chars)
{
	char	*buffer;
	int		read_size;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (free(buffer), NULL);
		buffer[read_size] = '\0';
		tmp = ft_strjoin(unused_chars, buffer);
		free(unused_chars);
		unused_chars = tmp;
		if (!unused_chars || !unused_chars[0])
			return (free(unused_chars), free(buffer), NULL);
	}
	return (free(buffer), unused_chars);
}
