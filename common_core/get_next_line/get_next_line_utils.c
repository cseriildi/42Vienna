/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:27:19 by icseri            #+#    #+#             */
/*   Updated: 2024/04/19 15:59:10 by icseri           ###   ########.fr       */
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

int	is_nl(char *read_chars)
{
	if (!read_chars)
		return (0);
	while (*read_chars)
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

	if (!read_chars || !read_chars[0])
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

char	*remove_line(char *read_chars)
{
	char	*trimmed;
	int		i;
	int		j;
	int		len;

	if (!read_chars /* || !read_chars[0] */)
		return (/* free(read_chars),  */NULL);
	len = ft_strlen(read_chars);
	i = 0;
	while (read_chars[i] && read_chars[i] != '\n')
		i++;
	if (read_chars[i] == '\n')
		i++;
	if (i == len)
		return (free(read_chars), NULL);
	trimmed = malloc(len - i + 1);
	if (!trimmed)
        return (NULL);
	j = 0;
	while (i < len)
		trimmed[j++] = read_chars[i++];
	trimmed[j] = '\0';
	free(read_chars);
	return (trimmed);
}
