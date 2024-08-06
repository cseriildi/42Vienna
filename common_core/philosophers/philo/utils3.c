/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:37:27 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/06 10:34:43 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, long long time, char *act)
{
	pthread_mutex_lock(philo->data->print);
	if (philo->status == ALIVE)
		printf("%lld %d %s\n", time, philo->id, act);
	pthread_mutex_unlock(philo->data->print);
}

void	send_obituary(t_data *data, int id)
{
	int	i;

	if (data->running == true)
	{
		pthread_mutex_lock(data->print);
		data->philos[id - 1].status = DEAD;
		printf("%lld %d died\n", get_elapsed_time(data), id);
		i = -1;
		while (++i < data->count)
		{
			if (data->philos[i].status != DEAD)
				data->philos[i].status = MOURNING;
		}
		data->running = false;
		pthread_mutex_unlock(data->print);
	}
}

void	check_if_all_full(t_data *data)
{
	int	i;
	int	count;

	if (data->min_eat_count == -1)
		return ;
	i = -1;
	count = 0;
	while (++i < data->count)
	{
		if (data->philos[i].status == FULL)
			count++;
	}
	if (count == data->count)
		data->running = false;
}

bool	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, get_elapsed_time(philo->data), "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, get_elapsed_time(philo->data), "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, get_elapsed_time(philo->data), "has taken a fork");
		if (philo->left_fork == philo->right_fork)
		{
			pthread_mutex_unlock(philo->right_fork);
			return (false);
		}
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, get_elapsed_time(philo->data), "has taken a fork");
	}
	return (true);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	if (philo->left_fork != philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
}

void	join_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->count)
		pthread_join(data->philos[i].thread, NULL);
	pthread_join(data->reaper, NULL);
}
