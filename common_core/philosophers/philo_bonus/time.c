/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:20:45 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/29 16:01:16 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_time(void)
{
	struct timeval	tv;
	long long		milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}

long long	get_elapsed_time(long long start_time)
{
	return (get_time() - start_time);
}

bool	check_if_dead(t_philo *philo)
{
	if (is_running(philo) == false)
		return (true);
	if (get_elapsed_time(philo->last_eating_time) >= philo->time_to_die)
	{
		dying(philo);
		return (true);
	}
	return (false);
}

bool	ft_usleep(long long time, t_philo *philo)
{
	long long	start;

	if (time == 0)
		return (!check_if_dead(philo));
	start = get_time();
	while (get_time() - start < time)
	{
		if (check_if_dead(philo) == true)
			return (false);
		usleep(100);
	}
	return (true);
}
