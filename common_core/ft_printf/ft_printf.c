/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:41:45 by icseri            #+#    #+#             */
/*   Updated: 2024/04/15 12:29:20 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_args(va_list args, char c)
{
	uintptr_t	p;

	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
	{
		p = (uintptr_t)va_arg(args, void *);
		if (!p)
			return (ft_putstr("(nil)"));
		ft_putstr("0x");
		return (ft_putnbr_ptr(p) + 2);
	}
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), c));
	if (c == '%')
		return (ft_putchar(c));
	return (0);
}

int	is_in_str(char *str, char c)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	if (s == NULL)
		return (counter);
	va_start(args, s);
	while (*s)
	{
		if (*s != '%')
			counter += ft_putchar(*s++);
		else
		{
			if (is_in_str("cspdiuxX%%", *++s) == 1)
				counter += write_args(args, *s++);
			else
			{
				counter += ft_putchar(*(s - 1));
				counter += ft_putchar(*s++);
			}
		}
	}
	va_end(args);
	return (counter);
}
/* 
int	main(int argc, char **argv)
{
	int	x = -78;
	unsigned int	y = 78;
	int	*p;
	int	ocount;
	int	mcount;
	char	*str = "Hello World!";
	void	*n = NULL;
	p = &x;

	ocount = printf("The printf prints this:
	\n[%c]\n[%s]\n[%p]\n[%d]\n[%i]\n[%u]\n[%x]\n[%X]\n[%%]\n",
		y, str, p, x, x, y, y, y);
	mcount = ft_printf(" ft_printf prints this:
	\n[%c]\n[%s]\n[%p]\n[%d]\n[%i]\n[%u]\n[%x]\n[%X]\n[%%]\n",
		y, str, p, x, x, y, y, y);
		
	printf("The original printed %d characters\n", ocount);
	printf("Mine printed %d characters\n", mcount);
	ocount = printf("The printf prints this:
	\n[%c]\n[%s]\n[%p]\n[%d]\n[%i]\n[%u]\n[%x]\n[%X]\n[%%]\n",
		NULL, NULL, n, NULL, NULL, NULL, NULL, NULL);
	mcount = ft_printf(" ft_printf prints this:
	\n[%c]\n[%s]\n[%p]\n[%d]\n[%i]\n[%u]\n[%x]\n[%X]\n[%%]\n",
		NULL, NULL, n, NULL, NULL, NULL, NULL, NULL);

	printf("The original printed %d characters\n", ocount);
	printf("Mine printed %d characters\n", mcount);
}
 */