/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:09:19 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/14 08:18:55 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_bonus.h"

t_inprocess_data	eating(t_inprocess_data philo)
{
	sem_wait(philo.forks);
	safe_print(philo, "has taken a fork");
	if (philo.philo_count == 1)
	{
		ft_usleep(philo.time_to_die, philo);
		sem_wait(philo.print);
		printf("%lld %d died\n", get_elapsed_time(philo.start_time), philo.id);
		sem_post(philo.dead);
		safe_process_exit(philo, EXIT_SUCCESS);
	}
	sem_wait(philo.forks);
	safe_print(philo, "has taken a fork");
	safe_print(philo, "is eating");
	philo.last_eating_time = get_time();
	ft_usleep(philo.time_to_eat, philo);
	philo.eat_count++;
	if (philo.eat_count == philo.min_eat_count)
		sem_post(philo.full);
	sem_post(philo.forks);
	sem_post(philo.forks);
	return (philo);
}

void	sleeping(t_inprocess_data philo)
{
	safe_print(philo, "is sleeping");
	ft_usleep(philo.time_to_sleep, philo);
}

void	thinking(t_inprocess_data philo)
{
	safe_print(philo, "is thinking");
	ft_usleep(philo.time_to_think, philo);
}
