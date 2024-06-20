/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:55:08 by icseri            #+#    #+#             */
/*   Updated: 2024/06/20 19:04:17 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	occ(char const *str, char c)
{
	int		counter;
	char	prev;

	prev = c;
	counter = 0;
	while (*str)
	{
		if (*str != c && prev == c)
			counter++;
		prev = *str;
		str++;
	}
	return (counter);
}

static void	array_free(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
	arr = NULL;
}

static char	**create_empty_array(char const *str, char c)
{
	int		count;
	int		i;
	char	**words;
	int		len;

	count = occ(str, c);
	words = ft_calloc(sizeof(char *) * (count + 1), 1);
	if (words == NULL)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		len = 0;
		while (*str && *str == c)
			str++;
		while (*str && *str != c)
		{
			str++;
			len++;
		}
		words[i] = ft_calloc(len + 1, 1);
		if (words[i] == NULL)
			return (array_free(words), NULL);
	}
	return (words);
}

char	**ft_split(char const *str, char c)
{
	char	**words;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	words = create_empty_array(str, c);
	if (words == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != c)
			words[i][j++] = *str;
		else if (j != 0)
		{
			i++;
			j = 0;
		}
		str++;
	}
	words[i + (j != 0)] = NULL;
	return (words);
}
