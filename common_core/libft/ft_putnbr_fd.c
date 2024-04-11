/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:51:53 by icseri            #+#    #+#             */
/*   Updated: 2024/04/11 16:04:49 by icseri           ###   ########.fr       */
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

void	ft_putnbr_fd(int nb, int fd)
{
	int	dig;
	int	curr;
	int	sign;

	sign = 1;
	if (nb < 0)
		sign = -1;
	dig = ft_nbrlen(nb);
	while (dig > 0)
	{
		if (sign == -1)
			ft_putchar_fd('-', fd);
		curr = nb / (ft_power(10, dig - 1) * sign);
		ft_putchar_fd(curr + '0', fd);
		if (curr == 0)
			curr = 1;
		nb = (nb % (curr * ft_power(10, dig - 1) * sign)) * sign;
		dig--;
		sign *= sign;
	}
}
/* 
int	main(int argc, char **argv)
{
	(void)argc;
	ft_putnbr_fd(atoi(argv[1]), atoi(argv[2]));
}
 */