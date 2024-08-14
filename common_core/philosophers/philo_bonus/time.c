/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:20:45 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/14 12:28:26 by cseriildii       ###   ########.fr       */
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
	int	i;

	if (is_running(philo) == false)
		return (true);
	if (get_elapsed_time(philo->last_eating_time) >= philo->time_to_die)
	{
		sem_wait(philo->sems.check_status);
		philo->running = false;
		sem_post(philo->sems.check_status);
		sem_wait(philo->sems.print);
		printf("%lld %d died\n",
			get_elapsed_time(philo->start_time), philo->id);
		sem_post(philo->sems.print);
		i = -1;
		while (++i < philo->count)
			sem_post(philo->sems.dead);
		return (true);
	}
	return (false);
}

bool	ft_usleep(long long time, t_philo *philo)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (check_if_dead(philo) == true)
			return (false);
		usleep(100);
	}
	return (true);
}
