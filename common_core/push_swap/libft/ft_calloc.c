/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:43:29 by icseri            #+#    #+#             */
/*   Updated: 2024/04/10 19:14:02 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size != 0 && nmemb != ((nmemb * size) / size))
		return (NULL);
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
