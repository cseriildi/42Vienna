/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:50:27 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/06 10:35:13 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	eating(t_philo *philo)
{
	if (take_forks(philo) == false)
		return (false);
	philo->last_eating_time = get_elapsed_time(philo->data);
	print_status(philo, philo->last_eating_time, "is eating");
	ft_usleep(philo->data->time_to_eat, philo->data);
	release_forks(philo);
	philo->times_eaten++;
	if (philo->times_eaten == philo->data->min_eat_count)
	{
		philo->status = FULL;
		check_if_all_full(philo->data);
	}
	return (true);
}

void	sleeping(t_philo *philo)
{
	if (philo->data->running == true)
	{
		print_status(philo, get_elapsed_time(philo->data), "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
	}
}

void	thinking(t_philo *philo)
{
	if (philo->data->running == true)
	{
		print_status(philo, get_elapsed_time(philo->data), "is thinking");
		if (philo->data->count % 2 == 1)
			ft_usleep(philo->data->time_to_eat * 2
				- philo->data->time_to_sleep, philo->data);
	}
}
