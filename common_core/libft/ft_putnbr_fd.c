/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:51:53 by icseri            #+#    #+#             */
/*   Updated: 2024/04/04 15:13:30 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_len(int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int nb, int fd)
{
	char	nbr_as_str[12];
	int		i;

	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (nb == 0)
		ft_putstr_fd("0", fd);
	else
	{
		if (nb < 0)
		{
			ft_putstr_fd("-", fd);
			nb *= -1;
		}
		i = ft_nbr_len(nb);
		nbr_as_str[i + 1] = '\0';
		while (nb > 0)
		{
			nbr_as_str[i] = nb % 10 + 48;
			nb /= 10;
			i--;
		}
		ft_putstr_fd(nbr_as_str, fd);
	}
}
/* 
int	main(int argc, char **argv)
{
	(void)argc;
	ft_putnbr_fd(atoi(argv[1]), atoi(argv[2]));
}
 */