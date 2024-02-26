/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:33:02 by icseri            #+#    #+#             */
/*   Updated: 2024/02/24 19:39:10 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	power(int a, int b)
{
	int	pow;
	int	i;

	pow = 1;
	i = 1;
	while (i <= b)
	{
		pow = pow * a;
		i++;
	}
	return (pow);
}

int	check_asc(char	*str, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (str[i] >= str[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int nb, int max_n, int n)
{
	char	nbr_as_str[10];
	int		i;
	int		x;

	x = nb;
	if (x / power(10, n -1) == 0)
		nbr_as_str[0] = '0';
	nbr_as_str[n] = '\0';
	i = n - 1;
	while (x > 0)
	{
		nbr_as_str[i] = x % 10 + 48;
		x = x / 10;
		i--;
	}
	if (check_asc(nbr_as_str, n) == 1)
	{
		ft_putstr(nbr_as_str);
		if (nb != max_n)
			ft_putstr(", ");
	}
}

void	ft_print_combn(int n)
{
	int	nb;
	int	i;
	int	max_nb;

	nb = 0;
	max_nb = 0;
	i = n;
	if (n < 10 && n > 0)
	{
		while (i > 0)
		{
			nb += (n - i) * power(10, i - 1);
			max_nb += (10 - i) * power(10, i - 1);
			i--;
		}
		while (nb <= max_nb)
		{
			ft_putnbr(nb, max_nb, n);
			nb++;
		}
	}
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	ft_print_combn(atoi(argv[1]));
}*/
