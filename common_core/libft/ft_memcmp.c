/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:21:01 by icseri            #+#    #+#             */
/*   Updated: 2024/04/08 16:48:22 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *) s1;
	tmp2 = (char *) s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)tmp1[i] != (unsigned char)tmp2[i])
			return ((unsigned char)tmp1[i] - (unsigned char)tmp2[i]);
		i++;
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %d \n", memcmp(argv[1], argv[2], atoi(argv[3])));
	printf("My function: %d \n", ft_memcmp(argv[1], argv[2], atoi(argv[3])));
}*/
