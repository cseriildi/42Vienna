/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:09:19 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/14 12:32:33 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	eating(t_philo *philo)
{
	sem_wait(philo->sems.forks);
	safe_print(philo, "has taken a fork");
	if (philo->count == 1)
	{
		if (ft_usleep(philo->time_to_die, philo) == false)
			return (false);
		sem_wait(philo->sems.print);
		printf("%lld %d died\n",
			get_elapsed_time(philo->start_time), philo->id);
		sem_post(philo->sems.dead);
		sem_post(philo->sems.print);
		return (false);
	}
	sem_wait(philo->sems.forks);
	safe_print(philo, "has taken a fork");
	safe_print(philo, "is eating");
	philo->last_eating_time = get_time();
	if (ft_usleep(philo->time_to_eat, philo) == false)
		return (false);
	philo->eat_count++;
	if (philo->eat_count == philo->min_eat_count)
		sem_post(philo->sems.full);
	sem_post(philo->sems.forks);
	sem_post(philo->sems.forks);
	return (true);
}

bool	sleeping(t_philo *philo)
{
	safe_print(philo, "is sleeping");
	if (ft_usleep(philo->time_to_sleep, philo) == false)
		return (false);
	return (true);
}

bool	thinking(t_philo *philo)
{
	safe_print(philo, "is thinking");
	if (ft_usleep(philo->time_to_think, philo) == false)
		return (false);
	return (true);
}