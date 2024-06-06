/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:51:53 by icseri            #+#    #+#             */
/*   Updated: 2024/05/23 22:00:39 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(unsigned int n)
{
	unsigned int	digit;

	digit = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static unsigned int	ft_power(unsigned int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_power(nb, power - 1));
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	unsigned int	dig;
	unsigned int	curr;
	int				count;

	count = 0;
	dig = ft_nbrlen(nb);
	while (dig > 0)
	{
		curr = nb / ft_power(10, dig - 1);
		count += ft_putchar(curr + '0');
		if (curr == 0)
			curr = 1;
		nb = nb % (curr * ft_power(10, dig - 1));
		dig--;
	}
	return (count);
}
