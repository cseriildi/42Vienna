/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:55:15 by icseri            #+#    #+#             */
/*   Updated: 2024/04/11 11:02:16 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char) *s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) s);
	return (NULL);
}
/* 
int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %s \n", strchr(argv[1], argv[2][0]));
	printf("My function: %s \n", ft_strchr(argv[1], argv[2][0]));
}
*/
