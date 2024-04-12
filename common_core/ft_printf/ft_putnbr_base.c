/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:51:53 by icseri            #+#    #+#             */
/*   Updated: 2024/04/12 22:21:14 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(long n, int base)
{
	int	digit;

	digit = 1;
	if (n < 0)
	{
		if (n / (base * -1) == 0)
			return (digit);
		else
		{
			n /= (base * -1);
			digit++;
		}
	}
	while (n / base != 0)
	{
		n /= base;
		digit++;
	}
	return (digit);
}

static long	ft_power(long nb, long power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_power(nb, power - 1));
}

int	ft_putnbr_base(long nb, char *baseformat)
{
	int	dig;
	int	curr;
	int	sign;
	int	base;
	int	counter;

	counter = 0;
	base = ft_strlen(baseformat);
	sign = 1;
	if (nb < 0)
		sign = -1;
	dig = ft_nbrlen(nb, base);
	while (dig > 0)
	{
		if (sign == -1)
			counter += ft_putchar('-');
		curr = nb / (ft_power(base, dig - 1) * sign);
		counter += ft_putchar(baseformat[curr]);
		if (curr == 0)
			curr = 1;
		nb = (nb % (curr * ft_power(base, dig - 1) * sign)) * sign;
		dig--;
		sign *= sign;
	}
	return (counter);
}
/* 
int	main(int argc, char **argv)
{
	char *p;
	
	p = "0";
	(void)argc;
	ft_putnbr_base(atoi(argv[1]), argv[2]));
	ft_putstr_fd("\n", 1);
	ft_putnbr_base((uintptr_t)&p, argv[2]));

}
 */