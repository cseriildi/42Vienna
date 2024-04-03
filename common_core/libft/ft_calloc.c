/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:43:29 by icseri            #+#    #+#             */
/*   Updated: 2024/04/03 17:16:56 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
    void    *p;

    p = malloc(nmemb * size);
	arr = (char *) p;
	while (nmemb--)
		*arr++ = 0;
	return (p);
}
/*
int main(int argc, char **argv)
{
	(void)argc;
	printf("Original function: %s\n", (char *)calloc(atoi(argv[1]), atoi(argv[2])));
	printf("My function: %s\n", (char *)ft_calloc(atoi(argv[1]), atoi(argv[2])));
}*/