/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:22:00 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/06 10:37:31 by cseriildii       ###   ########.fr       */
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

void	ft_usleep(long long time, t_data *data)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time && data->running == true)
		usleep(100);
}
