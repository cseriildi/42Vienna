/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:16:59 by icseri            #+#    #+#             */
/*   Updated: 2024/09/12 14:21:07 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (print_error(MALLOC_FAIL));
	if (init_data(data, argc, argv) != 0)
		return (free_data(data));
	pthread_mutex_lock(data->program);
	init_philos(data, data->philos);
	init_monitor(data);
	data->start_time = get_time();
	pthread_mutex_unlock(data->program);
	join_threads(data);
	return (free_data(data));
}
