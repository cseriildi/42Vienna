/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:16:59 by icseri            #+#    #+#             */
/*   Updated: 2024/08/06 15:25:18 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (print_error(MALLOC_FAIL));
	if (init_data(data, argc, argv) != 0)
		return (free_data(data));
	pthread_mutex_lock(data->program);
	if (init_philos(data, data->philos) != 0)
		return (pthread_mutex_unlock(data->program), free_data(data));
	if (init_monitor(data) != 0)
		return (pthread_mutex_unlock(data->program), free_data(data));
	data->start_time = get_time();
	pthread_mutex_unlock(data->program);
	join_threads(data);
	return (free_data(data));
}
