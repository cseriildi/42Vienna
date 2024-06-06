/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:08:37 by icseri            #+#    #+#             */
/*   Updated: 2024/04/03 17:16:47 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %d \n", isdigit(argv[1][0]));
	printf("My function: %d \n", ft_isdigit(argv[1][0]));
}
*/
