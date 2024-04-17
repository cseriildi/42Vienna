/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:17:48 by icseri            #+#    #+#             */
/*   Updated: 2024/04/17 15:21:48 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		nbr;
	long	l;

	nbr = 0;
	l = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (l != (l * 10 + *nptr - 48) / 10)
			return ((sign >= 0) * -1);
		l = l * 10 + *nptr - '0';
		nbr = nbr * 10 + *nptr++ - '0';
	}
	return (sign * nbr);
}
/* 
int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %d \n", atoi(argv[1]));
	printf("My function: %d \n", ft_atoi(argv[1]));
}
 */