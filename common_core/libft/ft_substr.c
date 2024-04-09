/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:14:16 by icseri            #+#    #+#             */
/*   Updated: 2024/04/09 10:54:02 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	unsigned int	str_len;

	i = 0;
	str_len = ft_strlen(s);
	if (start >= str_len)
		len = 0;
	else if (str_len - start < len)
		len = str_len;
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	while (len-- > 0)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
/* 
int	main(int argc, char **argv)
{
	char	*str;

	str = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
	printf("%s\n", str);
	free(str);
}
 */