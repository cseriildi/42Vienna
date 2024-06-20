/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:40:59 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/20 20:23:54 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_hex(char *str)
{
	int	num;
	int	sign;

	if (!str || !*str)
		return (0);
	sign = 1;
	num = 0;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str != '\0')
	{
		if (*str >= 'A' && 'F' >= *str)
			num = (num * 16) + (*str - 'A' + 10);
		else if (*str >= 'a' && 'f' >= *str)
			num = (num * 16) + (*str - 'a' + 10);
		else
			num = (num * 16) + (*str - '0');
		str++;
	}
	return (num * sign);
}
