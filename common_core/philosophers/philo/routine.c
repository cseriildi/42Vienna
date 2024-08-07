/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:32:57 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/07 14:13:58 by icseri           ###   ########.fr       */
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
	if (philo->type == EVEN)
		ft_usleep(philo->data->time_to_eat, philo->data);
	else if (philo->type == ODD_ONE_OUT)
		ft_usleep(philo->data->time_to_eat * 2, philo->data);
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

bool	is_alive(t_philo *philo)
{
	bool	alive;

	pthread_mutex_lock(philo->check_status);
	if (philo->status == ALIVE || philo->status == FULL)
		alive = true;
	else
		alive = false;
	pthread_mutex_unlock(philo->check_status);
	return (alive);
}
