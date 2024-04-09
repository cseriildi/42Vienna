/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:55:08 by icseri            #+#    #+#             */
/*   Updated: 2024/04/09 11:54:21 by icseri           ###   ########.fr       */
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

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**create_empty_array(char const *str, char c)
{
	int		count;
	int		i;
	char	**words;
	int		len;

	len = ft_strlen(str);
	count = occ(str, c);
	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (ft_free(words), NULL);
	i = 0;
	while (i < count)
	{
		words[i] = malloc(len + 1);
		if (words[i] == NULL)
			return (ft_free(words), NULL);
		i++;
	}
	words[i] = NULL;
	return (words);
}

char	**ft_split(char const *str, char c)
{
	char	**words;
	int		i;
	int		j;

	words = create_empty_array(str, c);
	if (words == NULL)
		return (ft_free(words), NULL);
	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != c)
			words[i][j++] = *str;
		else if (j != 0)
		{
			words[i][j] = '\0';
			i++;
			j = 0;
		}
		str++;
	}
	if (j != 0)
		words[i++][j] = '\0';
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
		printf("[%s]\n", words[i++]);
	printf("[%s]\n", words[i]);
	ft_free(words);
}
*/