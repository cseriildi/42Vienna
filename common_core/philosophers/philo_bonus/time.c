/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:20:45 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/13 22:21:09 by cseriildii       ###   ########.fr       */
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

void	check_if_dead(t_inprocess_data philo)
{
	if (get_elapsed_time(philo.last_eating_time) >= philo.time_to_die)
	{
		sem_wait(philo.print);
		printf("%lld %d died\n", get_elapsed_time(philo.start_time), philo.id);
		sem_post(philo.dead);
		usleep(100);
		safe_process_exit (philo, EXIT_SUCCESS);
	}
}

void	ft_usleep(long long time, t_inprocess_data philo)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
	{
		check_if_dead(philo);
		usleep(100);
	}
}
