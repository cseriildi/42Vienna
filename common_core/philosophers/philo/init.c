/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:59:38 by cseriildii        #+#    #+#             */
/*   Updated: 2024/07/29 13:46:01 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_philo *data)
{
	int			i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->count);
	if (!data->forks)
		return (MALLOC_FAIL);
	i = -1;
	while (++i < data->count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (MUTEX_INIT_FAIL);
	}
	return (EXIT_SUCCESS);
}

void	*func(void *arg)
{
	t_philo			*data;
	struct timeval	tv;
	long			*milliseconds;

	data = (t_philo *)arg;
	pthread_mutex_lock(&data->forks[0]);
	gettimeofday(&tv, NULL);
	milliseconds = get_time();
	if (milliseconds == NULL)
		return (NULL);
	//printf("%ld\n", *millis;econds);
	pthread_mutex_unlock(&data->forks[0]);
	return ((void *)milliseconds);
}

int	init_philos(t_philo *data)
{
	int		i;
	long	*result;

	data->philos = malloc(sizeof(pthread_t) * data->count);
	if (!data->philos)
		return (MALLOC_FAIL);
	i = -1;
	while (++i < data->count)
	{
		if (pthread_create(&data->philos[i], NULL, func, data) != 0)
			return (THREAD_CREATE_FAIL);
	}
	i = -1;
	while (++i < data->count)
	{
		if (pthread_join(data->philos[i],  (void **)&result) != 0)
			return (THREAD_JOIN_FAIL);
		if (result)
		{
			printf("Thread %d result: %ld\n", i, *result);
			free(result);
		}
	}
	return (EXIT_SUCCESS);
}
