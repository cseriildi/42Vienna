/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:27:12 by icseri            #+#    #+#             */
/*   Updated: 2024/04/11 09:59:15 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	tmp1 = (char *) dest;
	tmp2 = (char *) src;
	i = 0;
	if (tmp1 > tmp2)
	{
		while (n-- > 0)
			tmp1[n] = tmp2[n];
	}
	else
	{
		while (i < n)
		{
			tmp1[i] = tmp2[i];
			i++;
		}
	}
	return (dest);
}
/*
int main() 
{
	char str1[50] = "42Vienna";
	char str2[50] = "42Vienna";
	int n = 2;

	memmove(str1, str1 + 2, n);
	printf("Original function: %s\n", str1);
	ft_memmove(str2, str2 + 2 , n);
	printf("My function: %s\n", str2);
}*/