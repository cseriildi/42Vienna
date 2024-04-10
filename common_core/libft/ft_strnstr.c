/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:23:55 by icseri            #+#    #+#             */
/*   Updated: 2024/04/10 16:42:26 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (big == NULL && little != NULL && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *) big);
	while (big[i])
	{
		j = 0;
		while (little[j] && big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *) big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
/* 
int	main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %s\n", strnstr(argv[1], argv[2], atoi(argv[3])));
	printf("My function: %s\n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
}
 */