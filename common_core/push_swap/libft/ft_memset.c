/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:42:47 by icseri            #+#    #+#             */
/*   Updated: 2024/04/03 17:16:34 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*tmp;

	tmp = (char *) s;
	while (n--)
		*tmp++ = c;
	return (s);
}
/*
int main() 
{ 
    char str1[50] = "42Vienna";
    char str2[50] = "42Vienna";
    int c = 90;
    int n = 6;

    memset(str1, c, n);
	printf("Original function: %s\n", str1);
	ft_memset(str2, c, n);
	printf("My function: %s\n", str2);
}
*/
