/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:27:19 by icseri            #+#    #+#             */
/*   Updated: 2024/07/03 13:37:02 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
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
	if (!s1 && !s2)
		return (NULL);
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

void	ft_free(char **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}
