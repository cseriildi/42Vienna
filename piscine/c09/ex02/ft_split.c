/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:55:08 by icseri            #+#    #+#             */
/*   Updated: 2024/03/05 08:55:09 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_separator(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

char	**create_empty_array(char *str, char *charset)
{
	int		count;
	int		i;
	char	**words;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (is_separator(str[i], charset) == 0)
		{
			count++;
			while (str[i] && is_separator(str[i], charset) == 0)
				i++;
		}
		i++;
	}
	words = malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (i < count)
	{
		words[i++] = malloc(ft_strlen(str) + 1);
	}
	words[count] = NULL;
	return (words);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		c;
	char	**words;

	words = create_empty_array(str, charset);
	i = 0;
	j = 0;
	c = 0;
	while (str[i])
	{
		if (is_separator(str[i], charset) == 1
			&& is_separator(str[i + 1], charset) == 0)
		{
			if (c != 0)
			{
				words[j++][c] = '\0';
				c = 0;
			}
		}
		else if (is_separator(str[i], charset) == 0)
			words[j][c++] = str[i];
		i++;
	}
	return (words);
}
/*
int	main(int argc, char **argv)
{
	char	**words;
	int		i;

	(void)argc;
	words = ft_split(argv[1], argv[2]);
	i = 0;
	while (words[i])
		printf("%s\n", words[i++]);
	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}*/
