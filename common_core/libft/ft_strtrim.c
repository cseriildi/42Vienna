/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:40:00 by icseri            #+#    #+#             */
/*   Updated: 2024/04/08 19:27:56 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		i;

	if (!s1 || !set)
		return (0);
	while (*s1 && is_in_set(*s1, set) == 1)
		s1++;
	trimmed = malloc(ft_strlen(s1) + 1);
	if (trimmed == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		trimmed[i++] = *s1++;
	trimmed[i--] = '\0';
	while (i >= 0 && is_in_set(trimmed[i], set) == 1)
		trimmed[i--] = '\0';
	return (trimmed);
}

/* int	main(int argc, char **argv)
{
	printf("%s\n", ft_strtrim(argv[1], argv[2]));
} */
