/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:55:08 by icseri            #+#    #+#             */
/*   Updated: 2024/05/24 22:27:15 by cseriildii       ###   ########.fr       */
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
			return (ft_free(words), NULL);
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

/* int	main(int argc, char **argv)
{
	char	**words;
	int		i;

	(void)argc;
	words = ft_split(argv[1], argv[2][0]);
	i = 0;
	while (words[i])
		printf("[%s]\n", words[i++]);
	printf("[%s]\n", words[i]);
	ft_free(words);
} */