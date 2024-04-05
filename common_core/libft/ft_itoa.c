/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:52:33 by icseri            #+#    #+#             */
/*   Updated: 2024/04/05 10:40:17 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char	*nbr_as_str;
	int		i;

	i = 0;
	nbr_as_str = malloc(12);
	if (nbr_as_str == NULL)
		return (NULL);
	if (nb == -2147483648)
		return ("-2147483648");
	else if (nb == 0)
		return ("0");
	if (nb < 0)
	{
		nbr_as_str[0] = '-';
		nb *= -1;
		i++;
	}
	i += ft_nbrlen(nb);
	nbr_as_str[i + 1] = '\0';
	while (nb > 0)
	{
		nbr_as_str[i--] = nb % 10 + 48;
		nb /= 10;
	}
	return (nbr_as_str);
}
/* 
int	main(int argc, char **argv)
{
	printf("%s\n", ft_itoa(atoi(argv[1])));
}  */