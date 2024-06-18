/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:47:42 by icseri            #+#    #+#             */
/*   Updated: 2024/06/18 11:44:50 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
            convert_to_2d(&data->map[row][column], &data->map_2d[row][column]);
    }
}