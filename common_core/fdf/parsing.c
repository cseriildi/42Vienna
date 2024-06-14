/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:23:36 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/14 17:50:17 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_var *data)
{
	data->content = NULL;
	data->str_map = NULL;
	data->line = NULL;
	data->map = NULL;
	data->map_2d = NULL;
	data->display = NULL;
	data->image.img = NULL;
	data->window = NULL;
	data->height = 0;
	data->width = 0;
	data->scale = 20;
	data->x_offset = 0;
	data->y_offset = 0;
}

void	read_file(t_var	*data)
{
	char	*line;
	char	*tmp;
	int		fd;

	init_data(data);
	fd = open(data->filename, O_RDONLY);
	if (fd == -1)
		safe_exit(data, CANNOT_OPEN_FILE);
	data->content = get_next_line(fd);
	if (!data->content)
	{
		close(fd);
		ft_putendl_fd("File is empty or malloc failed in get_next_line", 2);
		exit(5);
	}
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(data->content, line);
		ft_free(&data->content);
		ft_free(&line);
		data->content = tmp;
		line = get_next_line(fd);
	}
	close(fd);
}

void	get_size(t_var *data)
{
	int	i;

	while (data->str_map[data->height])
	{
		data->line = ft_split(data->str_map[0], ' ');
		if (!data->line)
			safe_exit(data, MALLOC_FAIL);
		i = 0;
		while (data->line[i])
			i++;
		if (data->width == 0)
			data->width = i;
		else if (data->width != i)

		array_free((void **)data->line);
		data->height++;
	}
}

void	malloc_maps(t_var *data)
{
	int	i;

	get_size(data);
	data->map = ft_calloc(sizeof(t_point *), data->height + 1);
	if (!data->map)
		safe_exit(data, MALLOC_FAIL);
	data->map_2d = ft_calloc(sizeof(t_2d_point *), data->height + 1);
	if (!data->map_2d)
		safe_exit(data, MALLOC_FAIL);
	i = -1;
	while (++i < data->height)
	{
		data->map[i] = malloc(sizeof(t_point) * (data->width + 1));
		if (!data->map[i])
			safe_exit(data, MALLOC_FAIL);
		data->map_2d[i] = malloc(sizeof(t_2d_point) * (data->width + 1));
		if (!data->map_2d[i])
			safe_exit(data, MALLOC_FAIL);
	}
}

void	create_map(t_var *data)
{
	int		i;
	int		j;

	read_file(data);
	data->str_map = ft_split(data->content, '\n');
	ft_free(&data->content);
	if (!data->str_map)
		safe_exit(data, MALLOC_FAIL);
	malloc_maps(data);
	i = -1;
	while (data->str_map[++i])
	{
		data->line = ft_split(data->str_map[i], ' ');
		if (!data->line)
			safe_exit(data, MALLOC_FAIL);
		array_free((void **)data->str_map);
		j = 0;
		while (data->line[j] && j < data->width)
		{
			data->map[i][j].x = j;
			data->map[i][j].y = i;
			data->map[i][j].z = ft_atoi(data->line[j]);
			j++;
		}
		if (j != data->width || data->line[j])
			safe_exit(data, WRONG_INPUT);
		ft_free(data->line);
	}
}
