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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	full_lenght(int size, char **strs)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined_str;
	int		i;
	int		full_len;

	i = 0;
	full_len = full_lenght(size, strs) + (size - 1) * ft_strlen(sep) + 1;
	joined_str = malloc(sizeof(char) * full_len);
	if (size == 0 || joined_str == NULL)
	{
		joined_str = NULL;
		return (joined_str);
	}
	while (i < size - 1)
	{
		joined_str = ft_strcat(joined_str, strs[i]);
		joined_str = ft_strcat(joined_str, sep);
		i++;
	}
	joined_str = ft_strcat(joined_str, strs[i]);
	return (joined_str);
}
/*
int	main(int argc, char **argv)
{
	char	*sep = ", ";
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			argv[i - 1] = argv[i];
			i++;
		}
		argv[i] = NULL;
		printf("%s", ft_strjoin(argc - 1, argv, sep));
	}
	else
		printf("write a couple of strings after ./a.out");
}*/
