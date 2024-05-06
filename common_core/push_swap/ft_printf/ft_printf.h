/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:55:15 by icseri            #+#    #+#             */
/*   Updated: 2024/04/16 15:23:10 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_putnbr_hex(unsigned int nb, char format);
int		ft_putnbr_ptr(uintptr_t nb);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_printf(const char *str, ...);

#endif
