/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:21:11 by icseri            #+#    #+#             */
/*   Updated: 2024/02/24 12:45:16 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>

void	create_grid(int input[16], int grid[6][6])
{		
	int	r;
	int	c;
	int	s;
	int i;

	i = 0;
	s = 4 + 1;
	r = 0;
	c = 0;
	while (r < 6)
	{
		while (c < 6)
		{
			grid[r][c] = 0;
			c++;
		}
		r++;
		c = 0;
	}
	c = 1;
	while (c < s)
	{
		grid[0][c] = *input;
		input++;
		c++;
	}
	r = 1;
	while (r < s)
    {
        grid[r][s] = *input;
        input++;
        r++;
    }
	r = 1;
    while (r < s)
    {
        grid[r][0] = *input;
        input++;
        r++;
    }
	c = 1;
	while (c < s)
	{
		grid[s][c] = *input;
		input++;
		c++;
	}
}
