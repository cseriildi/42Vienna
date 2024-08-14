/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:44:25 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/14 08:57:26 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	simulation(t_philo *philo)
{
	t_inprocess_data	philo_data;
	
	philo_data = get_philo_data(philo, philo->data);
	safe_print(philo_data, "is thinking");
	ft_usleep(philo_data.initial_thinking_time, philo_data);
	while (true)
	{
		philo_data = eating(philo_data);
		sleeping(philo_data);
		thinking(philo_data);
	}
}

t_inprocess_data	get_philo_data(t_philo *philo, t_data *data)
{
	t_inprocess_data	philo_data;

	philo_data.id = philo->id;
	philo_data.initial_thinking_time = philo->initial_thinking_time;
	philo_data.time_to_die = data->time_to_die;
	philo_data.time_to_eat = data->time_to_eat;
	philo_data.time_to_sleep = data->time_to_sleep;
	philo_data.time_to_think = data->time_to_think;
	philo_data.philo_count = data->count;
	philo_data.start_time = data->start_time;
	philo_data.last_eating_time = philo_data.start_time;
	philo_data.eat_count = 0;
	philo_data.min_eat_count = data->min_eat_count;
	philo_data.sems.forks = data->sems.forks;
	philo_data.sems.dead = data->sems.dead;
	philo_data.sems.full = data->sems.full;
	philo_data.sems.print = data->sems.print;
	free(data->philos);
	free(data);
	//philo_data = open_semaphores(philo_data);
	return (philo_data);
}
/*
t_inprocess_data	open_semaphores(t_inprocess_data philo)
{
	philo.forks = sem_open("/forks", 0);
	if (philo.forks == 1)
		safe_process_exit (philo, SEM_FAIL);
	philo.full = sem_open("/full", 0);
	if (philo.full == SEM_FAILED)
		safe_process_exit (philo, SEM_FAIL);
	philo.print = sem_open("/print", 0);
	if (philo.print == SEM_FAILED)
		safe_process_exit (philo, SEM_FAIL);
	philo.dead = sem_open("/dead", 0);
	if (philo.dead == SEM_FAILED)
		safe_process_exit (philo, SEM_FAIL);
	return (philo);
}
*/