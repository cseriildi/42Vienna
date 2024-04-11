/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:52:33 by icseri            #+#    #+#             */
/*   Updated: 2024/04/11 10:42:48 by icseri           ###   ########.fr       */
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

static int	is_neg(int n)
{
	if (n <= 0)
		return (-1);
	return (1);
}

char	*ft_itoa(int nb)
{
	char	*nbr_as_str;
	int		i;

	i = ft_nbrlen(nb);
	nbr_as_str = ft_calloc(i + 1, 1);
	if (nbr_as_str == NULL)
		return (NULL);
	if (nb == 0)
		nbr_as_str[0] = '0';
	if (nb < 0)
		nbr_as_str[0] = '-';
	while (nb != 0)
	{
		nbr_as_str[--i] = ((nb % (10 * is_neg(nb))) * is_neg(nb)) + '0';
		nb /= (10 * is_neg(nb));
	}
	return (nbr_as_str);
}
/* 
int	main(int argc, char **argv)
{
	printf("%s\n", ft_itoa(atoi(argv[1])));
}
 */