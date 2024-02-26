/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:22:21 by icseri            #+#    #+#             */
/*   Updated: 2024/02/23 11:36:33 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb > 0 && nb <= 2147395600)
	{
		while (i * i < nb)
		{
			i++;
			if (i * i == nb)
				return (i);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		printf("\nsqrt(%s", argv[i]);
		printf(") = %d", ft_sqrt(atoi(argv[i])));
		i++;
	}
}

