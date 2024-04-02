/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:42:47 by icseri            #+#    #+#             */
/*   Updated: 2024/04/02 15:45:33 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void    *ft_memset(void *s, int c, size_t n)
{
    char *tmp;
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

    printf("%s", str1);
    ft_memset(str1, c, n);
    printf("\n%s\n", str1);

    printf("%s", str2);
    memset(str2, c, n);
    printf("\n%s\n", str2);
}
*/