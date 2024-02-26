/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:22:21 by icseri            #+#    #+#             */
/*   Updated: 2024/02/23 12:20:47 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb > 1)
	{
		while (i < nb)
		{
			if (nb % i == 0)
				return (ft_find_next_prime(nb + 1));
			i++;
		}
		return (nb);
	}
	return (2);
}
/*
int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		printf("\nThe next prime greater or equeal than (%s", argv[i]);
		printf(" is  %d", ft_find_next_prime(atoi(argv[i])));
		i++;
	}
}
*/
