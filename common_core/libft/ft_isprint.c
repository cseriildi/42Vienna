/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:30:28 by icseri            #+#    #+#             */
/*   Updated: 2024/04/03 17:16:44 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %d \n", isprint(argv[1][0]));
	printf("My function: %d \n", ft_isprint(argv[1][0]));
}
*/