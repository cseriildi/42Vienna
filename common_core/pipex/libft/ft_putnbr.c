/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:51:53 by icseri            #+#    #+#             */
/*   Updated: 2024/05/23 22:00:51 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	digit;

	digit = 1;
	if (n < 0)
	{
		if (n / -10 == 0)
			return (digit);
		else
		{
			n /= -10;
			digit++;
		}
	}
	while (n / 10 != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_power(nb, power - 1));
}

int	ft_putnbr(int nb)
{
	int	dig;
	int	curr;
	int	count;
	int	sign;

	sign = 1;
	if (nb < 0)
		sign = -1;
	count = 0;
	dig = ft_nbrlen(nb);
	while (dig > 0)
	{
		if (sign == -1)
			count += ft_putchar('-');
		curr = nb / (ft_power(10, dig - 1) * sign);
		count += ft_putchar(curr + '0');
		if (curr == 0)
			curr = 1;
		nb = (nb % (curr * ft_power(10, dig - 1) * sign)) * sign;
		dig--;
		sign *= sign;
	}
	return (count);
}
