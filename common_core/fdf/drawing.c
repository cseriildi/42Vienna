/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 08:13:22 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/19 15:58:45 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(t_point p1, t_point p2, t_var *data)
{
    double dx = abs(p2.x - p1.x);
    double dy = abs(p2.y - p1.y);
    int sign_x = p1.x < p2.x ? 1 : -1;
    int sign_y = p1.y < p2.y ? 1 : -1;
    double error = dx - dy;
    double error2;

    while (p1.x != p2.x || p1.y != p2.y)
    {
        if (p1.x >= 0 && p1.x <= WIDTH && p1.y >= 0 && p1.y <= HEIGHT)
            *(unsigned int *)(data->image.addr + (p1.y * data->image.line_len + p1.x * (data->image.bpp / 8))) = p1.color;
        error2 = error * 2;
        if (error2 > -dy)
        {
            error -= dy;
            p1.x += sign_x;
        }
        if (error2 < dx)
        {
            error += dx;
            p1.y += sign_y;
        }
    }
}


void	draw(t_var *data)
{

	int row;
	int column;
/* 	int pixel;
	int color;
	char *image_data;
	int bpp, size_line, endian;
	data->image.img = mlx_new_image(data->display, WIDTH, HEIGHT);
	image_data = mlx_get_data_addr(data->image.img, &bpp, &size_line, &endian);
 */

	create_2d(data);
	row = -1;
	while (++row < data->height)
	{
		column = -1;
		while (++column < data->width)
		{
/* 			int x = (int)data->map_2d[row][column].x;
			int y = (int)data->map_2d[row][column].y;
			color = data->map_2d[row][column].color;
			
			
			if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			{
				pixel = (x * bpp / 8) + (y * size_line);
				image_data[pixel] = color & 0xFF;
				image_data[pixel + 1] = (color >> 8) & 0xFF;
				image_data[pixel + 2] = (color >> 16) & 0xFF;
				image_data[pixel + 3] = (color >> 24) & 0xFF; 
			}			*/
			 if (column < data->width - 1)
				draw_line(data->map[row][column], data->map[row][column + 1], data);
			if (row < data->height - 1)
				draw_line(data->map[row][column], data->map[row + 1][column], data);
		}
	}
	mlx_put_image_to_window(data->display, data->window, data->image.img, 0, 0);
}