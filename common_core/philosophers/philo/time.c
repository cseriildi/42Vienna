/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:22:00 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/07 14:10:21 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;
	long long		milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}

long long	get_elapsed_time(t_data *data)
{
	return (get_time() - data->start_time);
}

long long	get_time_left(t_data *data)
{
	long long	time_left;
	long long	min_time_left;
	int			i;

	i = -1;
	min_time_left = data->time_to_die;
	while (++i < data->count)
	{
		pthread_mutex_lock(data->philos[i].check_status);
		time_left = data->time_to_die - (get_elapsed_time(data)
				- data->philos[i].last_eating_time);
		pthread_mutex_unlock(data->philos[i].check_status);
		if (time_left <= 0 && is_running(data) == true)
		{
			set_status(data, i + 1);
			return (time_left);
		}
		if (time_left < min_time_left)
			min_time_left = time_left;
	}
	return (min_time_left);
}

void	ft_usleep(long long time, t_data *data)
{
	long long	start;

	if (time == 0)
		return ;
	start = get_time();
	while (is_running(data) == true && get_time() - start < time)
		usleep(100);
}
