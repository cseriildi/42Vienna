/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:33:36 by icseri            #+#    #+#             */
/*   Updated: 2024/02/27 16:33:37 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <unistd.h>
#include <stdio.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_nbrlen(int n)
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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		i++;
	}
}
