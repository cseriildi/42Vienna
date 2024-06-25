/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:16:59 by icseri            #+#    #+#             */
/*   Updated: 2024/06/25 10:21:38 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *func()
{
	pthread_mutex_lock(&data->mutex);
	//do smth
	pthread_mutex_unlock(&data->mutex);
}

void	init_philos(t_philo *data)
{
	int			i;

	data->philos = malloc(sizeof(pthread_t) * data->count);
	if (!data->philos)
		safe_exit(data, MALLOC_FAIL);
	i = -1;
	while (++i < data->count)
	{
		if (pthread_create(&data->philos[i], NULL, &func, NULL) != 0)
			safe_exit(data, THREAD_CREATE_FAIL);
	}
	i = -1;
	while (++i < data->count)
	{
		if (pthread_join(data->philos[i], NULL) != 0)
			safe_exit(data, THREAD_JOIN_FAIL);
	}
}

int	main(int argc, char **argv)
{
	t_philo *data;

	data = malloc(sizeof(t_philo));
	data->count = atoi(argv[1]);
	pthread_mutex_init(&data->mutex, NULL);
	init_philos(data);
	pthread_mutex_destroy(&data->mutex);
}