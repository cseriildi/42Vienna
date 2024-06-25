/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:58:52 by icseri            #+#    #+#             */
/*   Updated: 2024/06/25 17:00:51 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	nbr_as_str = malloc(dig + 1 + (sign == -1));
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
	nbr_as_str[i] = '\0';
	return (nbr_as_str);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 && !s2)
		return (0);
	if ((!s1 && s2) || (s1 && !s2))
		return (1);
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
