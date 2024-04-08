/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:52:33 by icseri            #+#    #+#             */
/*   Updated: 2024/04/08 18:23:13 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char	*nbr_as_str;
	int		i;

	i = ft_nbrlen(nb);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	nbr_as_str = malloc(i + 1);
	if (nbr_as_str == NULL)
		return (NULL);
	if (nb == 0)
		nbr_as_str[0] = '0';
	if (nb < 0)
	{
		nbr_as_str[0] = '-';
		nb *= -1;
	}
	nbr_as_str[i--] = '\0';
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
}
*/