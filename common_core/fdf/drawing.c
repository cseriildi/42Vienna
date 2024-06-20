/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 08:13:22 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/20 22:07:59 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	get_direction(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

void	draw_line(t_point p1, t_point p2, t_var *data)
{
	data->delta_x = ft_abs((int)p2.x - (int)p1.x);
	data->delta_y = ft_abs((int)p2.y - (int)p1.y);
	data->sign_x = get_direction(p1.x, p2.x);
	data->sign_y = get_direction(p1.y, p2.y);
	data->error = data->delta_x - data->delta_y;
	while ((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y)
	{
		if (p1.x >= 0 && p1.x <= WIDTH && p1.y >= 0 && p1.y <= HEIGHT)
			*(unsigned int *)(data->img.addr + ((int)p1.y * data->img.ll
						+ (int)p1.x * (data->img.bpp / 8))) = p1.color;
		data->error2 = data->error * 2;
		if (data->error2 > -data->delta_y)
		{
			data->error -= data->delta_y;
			p1.x += data->sign_x;
		}
		if (data->error2 < data->delta_x)
		{
			data->error += data->delta_x;
			p1.y += data->sign_y;
		}
	}
}

void	draw(t_var *data)
{
	int	i;
	int	j;

	create_2d(data);
	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			if (j < data->width - 1)
				draw_line(data->map_2d[i][j], data->map_2d[i][j + 1], data);
			if (i < data->height - 1)
				draw_line(data->map_2d[i][j], data->map_2d[i + 1][j], data);
		}
	}
	mlx_put_image_to_window(data->display, data->window, data->img.img, 0, 0);
}
