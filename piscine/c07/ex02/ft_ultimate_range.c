/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:09:19 by icseri            #+#    #+#             */
/*   Updated: 2024/02/26 15:09:20 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*r;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	r = malloc(sizeof(int) * (max - min));
	if (r == NULL)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		r[i] = min + i;
		i++;
	}
	*range = r;
	return (max - min);
}
/*
int	main(int argc, char **argv)
{
	int	*range;

	if (argc == 3)
		printf("%d", ft_ultimate_range(&range, atoi(argv[1]), atoi(argv[2])));
	else
		printf("Enter two numbers after ./a.out ");
}*/
