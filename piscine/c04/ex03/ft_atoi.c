/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:17:48 by icseri            #+#    #+#             */
/*   Updated: 2024/02/21 17:27:39 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	nbr;

	nbr = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - 48;
		str++;
	}
	return (sign * nbr);
}
