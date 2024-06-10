/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:47:06 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/09 10:54:38 by cseriildii       ###   ########.fr       */
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
		return (ft_putendl_fd("Malloc failed", 2), 2);
	data->filename = argv[1];
	parsing(data);


	int i = 0;
	int j = 0;

	while (i < data->height)
	{
		j = 0;
		while ( j < data->width)
		{
			ft_printf("%d ", data->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}