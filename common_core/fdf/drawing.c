/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 08:13:22 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/18 11:54:01 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point p1, t_point p2, t_var *data)
{
//shit should happen here
}


void	draw(t_var *data)
{
	int row;
	int column;


	create_2d(data);
	row = -1;
	while (++row < data->height)
	{
		column = -1;
		while (++column < data->width)
		{
			if (column != data->width - 1)
				draw_line(data->map_2d[row][column], data->map_2d[row][column + 1], data);
			if (row != data->height - 1)
				draw_line(data->map_2d[row][column], data->map_2d[row + 1][column], data);
		}
	}
}