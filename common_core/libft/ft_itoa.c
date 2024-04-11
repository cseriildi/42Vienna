/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:52:33 by icseri            #+#    #+#             */
/*   Updated: 2024/04/11 16:14:30 by icseri           ###   ########.fr       */
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

char	*ft_itoa(int nb)
{
	char	*nbr_as_str;
	int		dig;
	int		curr;
	int		sign;
	int		i;

	sign = ft_power(-1, (nb < 0));
	dig = ft_nbrlen(nb);
	nbr_as_str = ft_calloc(dig + 1 + (sign == -1), 1);
	if (nbr_as_str == NULL)
		return (NULL);
	i = (sign == -1);
	while (dig-- > 0)
	{
		if (sign == -1)
			nbr_as_str[0] = '-';
		curr = nb / (ft_power(10, dig) * sign);
		nbr_as_str[i++] = curr + '0';
		if (curr == 0)
			curr = 1;
		nb = (nb % (curr * ft_power(10, dig) * sign)) * sign;
		sign *= sign;
	}
	return (nbr_as_str);
}
/* 
int	main(int argc, char **argv)
{
	printf("%s\n", ft_itoa(atoi(argv[1])));
}
 */