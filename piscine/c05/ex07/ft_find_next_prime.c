/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:22:21 by icseri            #+#    #+#             */
/*   Updated: 2024/02/29 11:01:05 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb > 1)
	{
		while (i * i <= nb && i <= 46340)
		{
			if (nb % i == 0)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	else if (ft_is_prime(nb))
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}
/*
int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		printf("\nThe next prime greater than or equal to %s", argv[i]);
		printf(" is %d", ft_find_next_prime(atoi(argv[i])));
		i++;
	}
}*/
