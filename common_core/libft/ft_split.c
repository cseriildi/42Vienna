/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:55:08 by icseri            #+#    #+#             */
/*   Updated: 2024/04/05 14:46:12 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	occ(char c, char const *str)
{
	int		counter;
	char	prev;

	prev = '\0';
	counter = 1;
	while (*str++)
	{
		if (*str == c && prev != c)
			counter++;
		prev = *str;
	}
	return (counter);
}

static char	**create_empty_array(char const *str, char c)
{
	int		count;
	int		i;
	char	**words;
	int		len;

	count = occ(c, str);
	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
	{
		while (count >= 0)
			free(words[count--]);
		return (free(words), NULL);
	}
	i = -1;
	while (++i < count)
	{
		words[i] = malloc(ft_strlen(str) + 1);
		if (words[i] == NULL)
		{
			while (i >= 0)
				free(words[i--]);
			return (free(words), NULL);
		}
	}
	return (words);
}

char	**ft_split(char const *str, char c)
{
	char	**words;
	int		i;
	int		j;

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
	if (j != 0)
		i++;
	words[i] = NULL;
	return (words);
}
/* 
int	main(int argc, char **argv)
{
	char	**words;
	int		i;

	(void)argc;
	words = ft_split(argv[1], argv[2][0]);
	i = 0;
	while (words[i])
		printf("%s\n", words[i++]);
	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}
 */