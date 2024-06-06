/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:44:55 by icseri            #+#    #+#             */
/*   Updated: 2024/05/23 22:14:00 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
}
