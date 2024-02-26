/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:33:02 by icseri            #+#    #+#             */
/*   Updated: 2024/02/15 13:42:29 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_separator(char a, char b, char c)
{
	char	comma;
	char	space;

	comma = ',';
	space = ' ';
	if (a < '7' || b < '8' || c < '9')
	{
		write(1, &comma, 1);
		write(1, &space, 1);
	}
}

void	write_numbers(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				write_numbers(i, j, k);
				write_separator(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
}*/
