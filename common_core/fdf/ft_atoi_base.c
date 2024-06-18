/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:40:59 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/18 11:21:17 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static int	get_len(char *base)
{
	int i;

	if (!base || !*base|| !base[1])
		return (0);
	i = 1;
	if (base[0] != '0' && ft_isdigit(base[0]))
		return (0);
	while (base[i] && ft_isdigit(base[i]) && base[i + 1] && ft_isdigit(base[i + 1]))
	{
		if (base[i] - base[i - 1] != 1)
			return (0);
		i++;
	}
	if (base[i] != 'a' && base[i] != 'A')
		return (0);
	while (base[i] && ft_isalpha(base[i]) && base[i + 1] && ft_isalpha(base[i + 1]))
	{
		if (base[i] - base[i - 1] != 1)
			return (0);
		i++;
	}
	if (base[i])
		return (0);
	return (i);
}

static int	get_value(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (ft_islower(c))
		return (c - 'a' + 10);
	if (ft_isupper(c))
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, char *base)
{
	int num;
	int i;
	int sign;
	int len;

	len = get_len(base);
	if (!str || !*str || len == 0)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	num = 0;
	while (get_value(*str) < len)
	{
		num *= len;
		num += get_value(*str);
		str++;
	}
	return (sign * num);
}