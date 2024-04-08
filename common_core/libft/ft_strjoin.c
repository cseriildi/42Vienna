/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:54:20 by icseri            #+#    #+#             */
/*   Updated: 2024/04/08 15:04:16 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	int		i;

	i = 0;
	joined_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joined_str == NULL)
		return (NULL);
	while (*s1)
		joined_str[i++] = *s1++;
	while (*s2)
		joined_str[i++] = *s2++;
	joined_str[i] = '\0';
	return (joined_str);
}
/*
int	main(int argc, char **argv)
{
	printf("%s\n", ft_strjoin(argv[1], argv[2]));
}*/
