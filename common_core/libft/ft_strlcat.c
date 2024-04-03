/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:21:57 by icseri            #+#    #+#             */
/*   Updated: 2024/04/03 17:16:03 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;	
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	j = 0;
	if (size <= dst_len)
		return (src_len + size);
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	char		dest1[50] = "42";
	char		dest2[50] = "42";
	const char	*src = "Vienna";
	size_t		size = 5;

	printf("Original function: %zu \n", strlcat(dest1, src, size));
	printf("My function: %zu \n", ft_strlcat(dest2, src, size));
}*/