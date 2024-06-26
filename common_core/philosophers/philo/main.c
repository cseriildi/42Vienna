/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:16:59 by icseri            #+#    #+#             */
/*   Updated: 2024/06/26 09:06:47 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*data;

	data = malloc(sizeof(t_philo));
	if (!data)
		return (print_error(MALLOC_FAIL), data->err);
	if (check_input(argc, argv, data) != 0)
		return (data->err);
	parsing(argc, argv, data);
	init_forks(data);
	if (init_philos(data) != 0)
		return (data->err);
	destroy_forks(data);
	return (0);
}
