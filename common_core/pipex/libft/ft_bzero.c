/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:44:23 by icseri            #+#    #+#             */
/*   Updated: 2024/04/11 10:00:40 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return (s);
}
/*
int main() 
{ 
    char str1[50] = "42Vienna";
    char str2[50] = "42Vienna";
    int n = 6;

    printf("%s", str1);
    bzero(str1 + 2, n);
    printf("\n%s\n", str1);

    printf("%s", str2);
    ft_bzero(str2 + 2, n);
    printf("\n%s\n", str2);
}
*/
