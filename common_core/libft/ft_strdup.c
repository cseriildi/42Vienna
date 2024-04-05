/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:34:25 by icseri            #+#    #+#             */
/*   Updated: 2024/04/05 10:43:44 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*duplicate;

	duplicate = malloc(sizeof(char) * ft_strlen(s));
	return (ft_strcpy(duplicate, s));
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %s\n", strdup(argv[1]));
	printf("My function: %s\n", ft_strdup(argv[1]));
}*/
