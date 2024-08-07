/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:32:57 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/09 14:40:31 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->min_eat_count == 0)
		return (NULL);
	pthread_mutex_lock(philo->data->program);
	pthread_mutex_unlock(philo->data->program);
	print_status(philo, "is thinking");
	ft_usleep(philo->initial_thinking_time, philo->data);
	while (is_running(philo->data) == true)
	{
		if (eating(philo) == false)
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	*monitoring(void *arg)
{
	t_data		*data;
	long long	time_left;

	data = (t_data *)arg;
	pthread_mutex_lock(data->program);
	if (data->min_eat_count == 0)
	{
		data->running = false;
		pthread_mutex_unlock(data->program);
		return (NULL);
	}
	pthread_mutex_unlock(data->program);
	while (is_running(data) == true)
	{
		time_left = get_time_left(data);
		ft_usleep(time_left, data);
	}
	return (NULL);
}

void	join_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->count)
		pthread_join(data->philos[i].thread, NULL);
	pthread_join(data->monitor, NULL);
}

bool	is_running(t_data *data)
{
	bool	running;

	pthread_mutex_lock(data->check_status);
	running = data->running;
	pthread_mutex_unlock(data->check_status);
	return (running);
}
