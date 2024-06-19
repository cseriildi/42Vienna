/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:47:42 by icseri            #+#    #+#             */
/*   Updated: 2024/06/19 07:56:23 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	set_borders(t_var *data, int row, int column)
{
	if (column == 0 && row == 0)
	{
		data->x_min = data->map_2d[row][column].x;
		data->x_max = data->map_2d[row][column].x;
		data->y_min = data->map_2d[row][column].y;
		data->y_max = data->map_2d[row][column].y;
	}
	else
	{
		if (data->map_2d[row][column].x < data->x_min)
			data->x_min = data->map_2d[row][column].x;
		if (data->map_2d[row][column].x > data->x_max)
			data->x_max = data->map_2d[row][column].x;
		if (data->map_2d[row][column].y < data->y_min)
			data->y_min = data->map_2d[row][column].y;
		if (data->map_2d[row][column].y > data->y_max)
			data->y_max = data->map_2d[row][column].y;
	}
}

void	adjust_map(t_var *data)
{
	int row;
	int column;
	int x_offset;
	int y_offset;

	x_offset = (WIDTH - (data->x_max - data->x_min)) / 2 - data->x_min;
	y_offset = (HEIGHT - (data->y_max - data->y_min)) / 2 - data->y_min;
	row = -1;
	while (++row < data->height)
	{
		column = -1;
		while (++column < data->width)
		{
			data->map_2d[row][column].x += x_offset;
			data->map_2d[row][column].y += y_offset;
		}
	}

}

double rad(int angle)
{
	return (angle * PI / 180);
}

void convert_to_2d(t_point *p3d, t_point *p2d)
{
	p2d->x = (p3d->x - p3d->y) * cos(rad(ANGLE));
	p2d->y = (p3d->x + p3d->y) * sin(rad(ANGLE)) - p3d->z;
	p2d->color = p3d->color;
}

void create_2d(t_var *data)
{
	int column;
	int row;


	row = -1;
	while (++row < data->height)
	{
		column = -1;
		while (++column < data->width)
		{
			convert_to_2d(&data->map[row][column], &data->map_2d[row][column]);
			set_borders(data, row, column);
		}
	}
	adjust_map(data);
}