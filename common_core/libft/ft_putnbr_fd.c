/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:51:53 by icseri            #+#    #+#             */
/*   Updated: 2024/04/11 10:49:37 by icseri           ###   ########.fr       */
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

void	ft_putnbr_fd(int nb, int fd)
{
	char	nbr_as_str[12];
	int		i;

	i = ft_nbrlen(nb);
	if (nb == 0)
		nbr_as_str[0] = '0';
	if (nb < 0)
		nbr_as_str[0] = '-';
	nbr_as_str[i--] = '\0';
	while (nb != 0)
	{
		nbr_as_str[i--] = ((nb % (10 * is_neg(nb))) * is_neg(nb)) + '0';
		nb /= (10 * is_neg(nb));
	}
	ft_putstr_fd(nbr_as_str, fd);
}
/* 
int	main(int argc, char **argv)
{
	(void)argc;
	ft_putnbr_fd(atoi(argv[1]), atoi(argv[2]));
}
 */