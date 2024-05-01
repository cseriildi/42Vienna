/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:55:15 by icseri            #+#    #+#             */
/*   Updated: 2024/04/10 16:32:11 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if ((unsigned char) s[len] == (unsigned char) c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %s \n", strrchr(argv[1], argv[2][0]));
	printf("My function: %s \n", ft_strrchr(argv[1], argv[2][0]));
}*/
