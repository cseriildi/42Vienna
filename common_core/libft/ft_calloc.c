/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:43:29 by icseri            #+#    #+#             */
/*   Updated: 2024/04/08 17:44:39 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, (nmemb * size));
	return (p);
}
/* 
int	main(int argc, char **argv)
{
	void	*p;

	(void)argc;
	p = calloc(atoi(argv[1]), atoi(argv[2]));
	printf("Original function: %p\n", p);
	free(p);
	p = ft_calloc(atoi(argv[1]), atoi(argv[2]));
	printf("My function: %p\n", p);
	free(p);
}
*/
