/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:32:57 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/05 19:45:13 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->data->program);
	pthread_mutex_unlock(philo->data->program);
	//thinking(philo);
	while (philo->status == ALIVE)
	{
		eating(philo);
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
	t_data	*data;
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

void	switch_from_to(int old_type, int type, t_data *data)
{
	int	i;
	
	if (data->running == false)
		return ;
	i = -1;
	while (++i < data->count)
	{
		if (old_type != -1 && data->philos[i].type == old_type)
			pthread_mutex_lock(&data->handcuffs[i]);
	}
	i = -1;
	while (++i < data->count)
	{
		if (data->philos[i].type == type)
			pthread_mutex_unlock(&data->handcuffs[i]);
	}
	ft_usleep(data->time_to_eat, data);
}

void	*waiter(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	pthread_mutex_lock(data->program);
	i = -1;
	while (++i < data->count)
		pthread_mutex_lock(&data->handcuffs[i]);
	pthread_mutex_unlock(data->program);
	switch_from_to(-1, ODD, data);
	while (data->running == true)
	{
		switch_from_to(ODD, EVEN, data);
		if (data->count != 1 && data->count % 2 == 1)
			switch_from_to(EVEN, ODD_ONE_OUT, data);
		switch_from_to(ODD_ONE_OUT, ODD, data);
	}
	return (NULL);
}
