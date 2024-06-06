/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:00:25 by icseri            #+#    #+#             */
/*   Updated: 2024/04/11 09:59:00 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	i = 0;
	tmp1 = (char *) dest;
	tmp2 = (char *) src;
	if (!tmp1 && !tmp2)
		return (NULL);
	while (n--)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (dest);
}
/* 
int main() 
{
	char str1[50] = "98Vienna";
	char str2[50] = "98Vienna";
	const char *str3 = "42";
	int n = 2;

	memcpy(str1, str3, n);
	printf("Original function: %s\n", str1);
	ft_memcpy(str2, str3, n);
	printf("My function: %s\n", str2);
}
 */