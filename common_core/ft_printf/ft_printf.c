/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:41:45 by icseri            #+#    #+#             */
/*   Updated: 2024/04/12 19:14:37 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/

static int	write_args(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_putnbr_base(
			(uintptr_t)va_arg(args, void *), "0123456789abcdef") + 2);
	if (c == 'd' || c == 'i' || c == 'u')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar(c));
}

int	ft_printf(const char *str, ...)
{
	char	*s;
	int		i;
	va_list	args;
	int		counter;

	counter = 0;
	if (str == NULL)
		return (counter);
	s = (char *) str;
	va_start(args, str);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			write(1, &s[i++], 1);
			counter++;
		}
		else
		{
			counter += write_args(args, s[i + 1]);
			i += 2;
		}
	}
	va_end(args);
	return (counter);
}
/* 
int	main(int argc, char **argv)
{
	int		x = 12;
	void	*p;

	p = &x;

	printf("The original prints this: \n[%p]\n[%X]\n[%%]\n", p, x);
	ft_printf("Mine prints this: \n[%p]\n[%X]\n[%%]\n", p, x);
}
 */