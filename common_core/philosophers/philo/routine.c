/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:32:57 by cseriildii        #+#    #+#             */
/*   Updated: 2024/07/31 11:33:31 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_status(t_philo *philo, long time, char *act)
{
	pthread_mutex_lock(philo->data->print_lock);
	printf("%ld %d %s\n", time, philo->id, act);
	pthread_mutex_unlock(philo->data->print_lock);
}

long get_elapsed_time(t_data *data)
{
	return (get_time() - data->start_time);
}
void	*routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *)arg;
	while (true)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, get_elapsed_time(philo->data), "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, get_elapsed_time(philo->data), "has taken a fork");
		philo->last_eating_time = get_time() - philo->data->start_time;
		print_status(philo, get_elapsed_time(philo->data), "is eating");
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		philo->times_eaten++;
		philo->last_eating_time = get_elapsed_time(philo->data);
		print_status(philo, get_elapsed_time(philo->data), "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
		print_status(philo, get_elapsed_time(philo->data), "is thinking");
	}
	return NULL;
}
