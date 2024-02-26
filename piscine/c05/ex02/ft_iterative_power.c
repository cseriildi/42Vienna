/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:58:29 by icseri            #+#    #+#             */
/*   Updated: 2024/02/22 21:09:02 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	pow;

	i = 1;
	pow = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		while (i < power)
		{
			pow *= nb;
			i++;
		}
		return (pow);
	}
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s", argv[1]);
	printf(" ** ""%s", argv[2]);
	printf(" = ""%d", ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
}
*/
