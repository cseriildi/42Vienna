/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:30:28 by icseri            #+#    #+#             */
/*   Updated: 2024/02/20 09:53:26 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	while (*str != '\0')
	{
		if (*str < 32 || *str == 127)
		{
			ft_putchar('\\');
			ft_putchar(hexa[*str / 16]);
			ft_putchar(hexa[*str % 16]);
		}
		else
			ft_putchar(*str);
		str++;
	}
}
