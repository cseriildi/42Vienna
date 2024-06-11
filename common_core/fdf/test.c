/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:11:35 by icseri            #+#    #+#             */
/*   Updated: 2024/06/11 17:05:11 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_var *data)
{
	data->content = NULL;
	data->str_map = NULL;
	data->map = NULL;
	data->mlx = NULL;
	data->window = NULL;
}

int	main(void)
{
	t_var *data;

	data = malloc(sizeof(t_var));
	if (!data)
		safe_exit(data, MALLOC_FAIL);
	init_data(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		safe_exit(data, MALLOC_FAIL);
	data->window = mlx_new_window(data->mlx, 5, 5, "dssdks");
	if (!data->window)
		safe_exit(data, MALLOC_FAIL);
	mlx_hook(data->window,); //?????

	mlx_loop(data->mlx);
}