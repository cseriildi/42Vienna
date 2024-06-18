/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 08:13:22 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/18 12:04:36 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point p1, t_point p2, t_var *data)
{
	int dx;
	int dy;
	int error;
	int error2;
	int sign_x;
	int sign_y;
	int x;
	int y;

	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	sign_x = p1.x < p2.x ? 1 : -1;
	sign_y = p1.y < p2.y ? 1 : -1;
	error = dx - dy;
	x = p1.x;
	y = p1.y;
	while (x != p2.x || y != p2.y)
	{
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			*(unsigned int *)(data->image.addr + (y * data->image.line_len + x * (data->image.bpp / 8))) = p1.color;
		error2 = error * 2;
		if (error2 > -dy)
		{
			error -= dy;
			x += sign_x;
		}
		if (error2 < dx)
		{
			error += dx;
			y += sign_y;
		}
	}
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