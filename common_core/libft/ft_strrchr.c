/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:55:15 by icseri            #+#    #+#             */
/*   Updated: 2024/04/04 16:29:47 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char *) s + len);
		len--;
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %s \n", strrchr(argv[1], argv[2][0]));
	printf("My function: %s \n", ft_strrchr(argv[1], argv[2][0]));
}*/
