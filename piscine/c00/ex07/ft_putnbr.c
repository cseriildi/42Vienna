/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:21:57 by icseri            #+#    #+#             */
/*   Updated: 2024/02/24 19:31:55 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_nbrlen(unsigned int n)
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

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	char	nbr_as_str[12];
	int		i;

	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else if (nb == 0)
		ft_putstr("0");
	else
	{
		if (nb < 0)
		{
			ft_putstr("-");
			nb *= -1;
		}
		i = ft_nbrlen(nb);
		nbr_as_str[i + 1] = '\0';
		while (nb > 0)
		{
			nbr_as_str[i] = nb % 10 + 48;
			nb = nb / 10;
			i--;
		}
		ft_putstr(nbr_as_str);
	}
}
/*
int	main(int argc, char **argv)
{
	int	i;
	
	i = 1;
	while (i < argc)
	{
		ft_putnbr(atoi(argv[i]));
		i++;
	}
}*/
