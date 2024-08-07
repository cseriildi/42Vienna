/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:50:27 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/07 12:37:05 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	eating(t_philo *philo)
{
	bool	is_full;	

	is_full = false;
	if (take_forks(philo) == false)
		return (false);
	pthread_mutex_lock(philo->check_status);
	philo->last_eating_time = get_elapsed_time(philo->data);
	pthread_mutex_unlock(philo->check_status);
	print_status(philo, "is eating");
	ft_usleep(philo->data->time_to_eat, philo->data);
	release_forks(philo);
	pthread_mutex_lock(philo->check_status);
	philo->times_eaten++;
	if (philo->times_eaten == philo->data->min_eat_count)
	{
		philo->status = FULL;
		is_full = true;
	}
	pthread_mutex_unlock(philo->check_status);
	if (is_full == true && check_if_all_full(philo->data) == true)
		return (false);
	return (true);
}

void	sleeping(t_philo *philo)
{
	if (is_running(philo->data) == true)
	{
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
	}
}

void	thinking(t_philo *philo)
{
	if (is_running(philo->data) == true)
	{
		print_status(philo, "is thinking");
		if (philo->data->count % 2 == 1)
			ft_usleep(philo->data->time_to_eat * 2
				- philo->data->time_to_sleep, philo->data);
		else
			ft_usleep(philo->data->time_to_eat
				- philo->data->time_to_sleep, philo->data);
	}
}

bool	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		if (philo->left_fork == philo->right_fork)
		{
			pthread_mutex_unlock(philo->right_fork);
			return (false);
		}
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	return (true);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	if (philo->left_fork != philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
}
