/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:54:20 by icseri            #+#    #+#             */
/*   Updated: 2024/02/27 11:55:30 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	total_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			len++;
		j = 0;
		while (sep[j++] && i < size - 1)
			len++;
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined_str;
	int		s;
	int		c;
	int		j;

	joined_str = malloc(sizeof(char) * (total_len(size, strs, sep) + 1));
	if (size == 0 || joined_str == NULL)
		return (NULL);
	s = 0;
	j = 0;
	while (s < size)
	{
		c = 0;
		while (strs[s][c])
			joined_str[j++] = strs[s][c++];
		c = 0;
		while (sep[c] && s < size - 1)
			joined_str[j++] = sep[c++];
		s++;
	}
	joined_str[j] = '\0';
	return (joined_str);
}
/*
int	main(int argc, char **argv)
{
	char	*sep;
	int		i;

	sep = ", ";
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			argv[i - 1] = argv[i];
			i++;
		}
		argv[i] = NULL;
		printf("%s\n", ft_strjoin(argc - 1, argv, sep));
	}
	else
		printf("write a couple of strings after ./a.out");
}*/
