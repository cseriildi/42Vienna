/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:51:53 by icseri            #+#    #+#             */
/*   Updated: 2024/05/23 22:00:20 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nbrlen(unsigned int n)
{
	int	digit;

	digit = 1;
	while (n / 16 != 0)
	{
		n /= 16;
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

int	ft_putnbr_hex(unsigned int nb, char format)
{
	unsigned int	dig;
	unsigned int	curr;
	int				counter;
	char			*baseformat;

	if (format == 'x')
		baseformat = "0123456789abcdef";
	else
		baseformat = "0123456789ABCDEF";
	counter = 0;
	dig = ft_nbrlen(nb);
	while (dig > 0)
	{
		curr = nb / ft_power(16, dig - 1);
		counter += ft_putchar(baseformat[curr]);
		if (curr == 0)
			curr = 1;
		nb = nb % (curr * ft_power(16, dig - 1));
		dig--;
	}
	return (counter);
}
