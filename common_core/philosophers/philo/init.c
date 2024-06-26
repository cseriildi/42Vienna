/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:59:38 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/26 11:44:54 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_philo *data)
{
	int			i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->count);
	if (!data->forks)
		return (free_data(data, MALLOC_FAIL), MALLOC_FAIL);
	i = -1;
	while (++i < data->count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (free_data(data, MUTEX_INIT_FAIL), MUTEX_INIT_FAIL);
	}
	return (0);
}

void	*func(void *arg)
{
	t_philo			*data;
	struct timeval	tv;
	long			milliseconds;

	data = (t_philo *)arg;
	pthread_mutex_lock(&data->forks[0]);
	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("%ld\n", milliseconds);
	pthread_mutex_unlock(&data->forks[0]);
	return (NULL);
}

int	init_philos(t_philo *data)
{
	int			i;

	data->philos = malloc(sizeof(pthread_t) * data->count);
	if (!data->philos)
		return (free_data(data, MALLOC_FAIL), MALLOC_FAIL);
	i = -1;
	while (++i < data->count)
	{
		if (pthread_create(&data->philos[i], NULL, func, data) != 0)
			return (free_data(data, THREAD_CREATE_FAIL), THREAD_CREATE_FAIL);
	}
	i = -1;
	while (++i < data->count)
	{
		if (pthread_join(data->philos[i], NULL) != 0)
			return (free_data(data, THREAD_JOIN_FAIL), THREAD_JOIN_FAIL);
	}
	return (0);
}
