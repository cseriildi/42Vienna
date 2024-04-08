/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:11:55 by icseri            #+#    #+#             */
/*   Updated: 2024/04/08 19:23:39 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) s;
	while (n-- > 0)
	{
		if (*tmp == (unsigned char) c)
			return ((void *)tmp);
		tmp++;
	}
	return (0);
}
/* 
int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %s \n",
		(char *) memchr(argv[1], argv[2][0], atoi(argv[3])));
	printf("My function: %s \n",
		(char *) ft_memchr(argv[1], argv[2][0], atoi(argv[3])));
} */
