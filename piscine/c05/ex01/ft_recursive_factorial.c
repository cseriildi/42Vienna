/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:18:05 by icseri            #+#    #+#             */
/*   Updated: 2024/02/22 20:54:34 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}
/*
int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		printf("\n""%s", argv[i]);
		printf("! = " "%d", ft_recursive_factorial(atoi(argv[i])));
		i++;
	}
}
*/
