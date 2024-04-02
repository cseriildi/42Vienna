/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:00:25 by icseri            #+#    #+#             */
/*   Updated: 2024/04/02 15:43:15 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *) dest;
	tmp2 = (char *) src;
	while (n--)
		tmp1[n] = tmp2[n];
	return (dest);
}
/*
int main() 
{ 
    char str1[50] = "98Vienna";
    char str2[50] = "98Vienna";
	char str3[2] = "42";
    int n = 2;

    printf("%s", str1);
    ft_memcpy(str1, str3, n);
    printf("\n%s\n", str1);

    printf("%s", str2);
    memcpy(str2, str3, n);
    printf("\n%s\n", str2);
}*/
