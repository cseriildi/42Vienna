/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:21:01 by icseri            #+#    #+#             */
/*   Updated: 2024/04/11 10:57:52 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *) s1;
	tmp2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i])
			return (tmp1[i] - tmp2[i]);
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
}
*/