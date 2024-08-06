/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:32:57 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/06 10:38:01 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->data->program);
	pthread_mutex_unlock(philo->data->program);
	print_status(philo, get_elapsed_time(philo->data), "is thinking");
	if (philo->type == EVEN)
		ft_usleep(philo->data->time_to_eat, philo->data);
	else if (philo->type == ODD_ONE_OUT)
		ft_usleep(philo->data->time_to_eat * 2, philo->data);
	while (philo->status == ALIVE)
	{
		if (eating(philo) == false)
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

long	get_time_left(t_data *data)
{
	long long	time_left;
	long long	min_time_left;
	int			i;

	i = -1;
	min_time_left = data->time_to_die;
	while (++i < data->count)
	{
		time_left = data->time_to_die - (get_elapsed_time(data)
				- data->philos[i].last_eating_time);
		if (time_left < 0 && data->running == true)
		{
			send_obituary(data, i + 1);
			return (time_left);
		}
		if (time_left < min_time_left)
			min_time_left = time_left;
	}
	return (min_time_left);
}

void	*kill_starver(void *arg)
{
	t_data		*data;
	long long	time_left;

	data = (t_data *)arg;
	pthread_mutex_lock(data->program);
	pthread_mutex_unlock(data->program);
	while (data->running == true)
	{
		time_left = get_time_left(data);
		ft_usleep(time_left / 2, data);
	}
	return (NULL);
}
