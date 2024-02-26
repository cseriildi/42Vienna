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

	if (min >= max)
		return (0);
	i = 0;
	while (range[1] <= max)
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (i < atoi(argv[2]) - atoi(argv[1]))
		{
			printf("%d ", ft_range(atoi(argv[1]), atoi(argv[2]))[i]);
			i++;
		}
	}
	else
		printf("Enter two numbers after ./a.out to get the range between them");
}*/
