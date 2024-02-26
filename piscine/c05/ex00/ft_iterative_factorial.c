/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:43:38 by icseri            #+#    #+#             */
/*   Updated: 2024/02/22 18:13:38 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	fact;

	fact = 1;
	i = 1;
	if (nb >= 0)
	{
		while (i <= nb && i > 0)
		{
			fact *= i;
			i++;
		}
		return (fact);
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		printf("\n""%s", argv[i]);
		printf("! = ""%d", ft_iterative_factorial(atoi(argv[i])));
		i++;
	}
}
*/
