/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:44:23 by icseri            #+#    #+#             */
/*   Updated: 2024/04/02 16:24:24 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void    *ft_bzero(void *s, size_t n)
{
    char *tmp;
    tmp = (char *) s;
    while (n--)
        *tmp++ = 0;
    return (s);
}
/*
int main() 
{ 
    char str1[50] = "42Vienna";
    char str2[50] = "42Vienna";
    int n = 6;

    printf("%s", str1);
    ft_bzero(str1 + 2, n);
    printf("\n%s\n", str1);

    printf("%s", str2);
    bzero(str2 + 2, n);
    printf("\n%s\n", str2);
}
*/