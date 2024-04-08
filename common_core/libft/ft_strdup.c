/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:34:25 by icseri            #+#    #+#             */
/*   Updated: 2024/04/08 17:56:03 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;

	duplicate = malloc(ft_strlen(s) + 1);
	if (duplicate == NULL)
		return (NULL);
	ft_memcpy(duplicate, s, ft_strlen(s) + 1);
	return (duplicate);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %s\n", strdup(argv[1]));
	printf("My function: %s\n", ft_strdup(argv[1]));
}*/
