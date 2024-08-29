/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:09:19 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/29 16:19:13 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	eating(t_philo *philo)
{
	if (take_forks(philo) == false)
		return (false);
	safe_print(philo, "is eating");
	philo->last_eating_time = get_time();
	if (ft_usleep(philo->time_to_eat, philo) == false)
	{
		sem_post(philo->sems.forks);
		sem_post(philo->sems.forks);
		return (false);
	}
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

bool	take_forks(t_philo *philo)
{
	if (philo->count != 1)
		sem_wait(philo->sems.take2forks);
	if (is_running(philo) == false)
		return (false);
	sem_wait(philo->sems.forks);
	safe_print(philo, "has taken a fork");
	if (philo->count == 1)
	{
		if (ft_usleep(philo->time_to_die, philo) == false)
			return (false);
		dying(philo);
		return (false);
	}
	sem_wait(philo->sems.forks);
	safe_print(philo, "has taken a fork");
	sem_post(philo->sems.take2forks);
	return (true);
}

void	dying(t_philo *philo)
{
	int	i;

	sem_wait(philo->sems.print);
	if (is_running(philo) == true)
	{
		printf("%lld %d died\n",
			get_elapsed_time(philo->start_time), philo->id);
		i = -1;
		while (++i <= philo->count)
			sem_post(philo->sems.dead);
	}
	else
		sem_post(philo->sems.print);
}
