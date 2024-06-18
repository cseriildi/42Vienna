/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:11:35 by icseri            #+#    #+#             */
/*   Updated: 2024/06/18 11:33:42 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_var *data;

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
	data->image.img = mlx_new_image(data->display, WIDTH, HEIGHT);
	if (!data->image.img)
		safe_exit(data, MALLOC_FAIL);
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bpp,
		&data->image.line_len, &data->image.endian);
	draw(data);
	mlx_put_image_to_window(data->display, data->window, data->image.img, 0, 0);
	mlx_key_hook(data->window, handle_esc, data);
	mlx_hook(data->window, CLICK_ON_X, 0, handle_close, data);
	mlx_loop(data->display);
	safe_exit(data, EXIT_SUCCESS);
}