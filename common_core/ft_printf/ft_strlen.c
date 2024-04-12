/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:54:28 by icseri            #+#    #+#             */
/*   Updated: 2024/04/12 18:49:44 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %lu \n", strlen(argv[1]));
	printf("My function: %lu \n", ft_strlen(argv[1]));
}
*/