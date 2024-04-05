/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:14:16 by icseri            #+#    #+#             */
/*   Updated: 2024/04/04 16:14:36 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	unsigned int	slen;

	slen = ft_strlen(s);
	i = 0;
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	while (len-- > 0 && start < slen)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
/* 
int	main(int argc, char **argv)
{
	printf("%s\n", ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
}
 */
