/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:00:25 by icseri            #+#    #+#             */
/*   Updated: 2024/04/10 16:20:19 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %d \n", tolower(argv[1][0]));
	printf("My function: %d \n", ft_tolower(argv[1][0]));
}*/
