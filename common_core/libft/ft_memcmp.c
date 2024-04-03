/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:21:01 by icseri            #+#    #+#             */
/*   Updated: 2024/04/03 17:16:41 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *) s1;
	tmp2 = (char *) s2;
	while (n-- > 0 && (*tmp1 || *tmp2))
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		tmp1++;
		tmp2++;
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
