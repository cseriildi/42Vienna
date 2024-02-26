/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:21:57 by icseri            #+#    #+#             */
/*   Updated: 2024/02/25 14:06:13 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_len;	
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dest_len;
	j = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[j] && i < size - 1)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ft_strlcat(argv[1], argv[2], atoi(argv[3])));
}*/
