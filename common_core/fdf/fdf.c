/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:11:35 by icseri            #+#    #+#             */
/*   Updated: 2024/06/20 21:14:20 by icseri           ###   ########.fr       */
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
	data->img.img = NULL;
	data->window = NULL;
	data->height = 0;
	data->width = 0;
	data->scale = 1;
	data->x_offset = 0;
	data->y_offset = 0;
}

int	main(int argc, char **argv)
{
	t_var	*data;

	if (argc != 2)
		return (ft_putendl_fd("Missing argument", 2), 1);
	data = malloc(sizeof(t_var));
	if (!data)
		safe_exit(data, MALLOC_FAIL);
	data->filename = argv[1];
	create_map(data);
	data->display = mlx_init();
	if (!data->display)
		safe_exit(data, MALLOC_FAIL);
	data->window = mlx_new_window(data->display, WIDTH, HEIGHT, "fdf");
	if (!data->window)
		safe_exit(data, MALLOC_FAIL);
	data->img.img = mlx_new_image(data->display, WIDTH, HEIGHT);
	if (!data->img.img)
		safe_exit(data, MALLOC_FAIL);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.ll, &data->img.en);
	draw(data);
	mlx_key_hook(data->window, handle_esc, data);
	mlx_hook(data->window, CLICK_ON_X, 0, handle_close, data);
	mlx_loop(data->display);
	safe_exit(data, EXIT_SUCCESS);
}
