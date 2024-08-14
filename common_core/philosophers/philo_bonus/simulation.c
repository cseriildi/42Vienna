/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:44:25 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/14 12:34:48 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	simulation(t_philo *philo)
{
	if (pthread_create(&philo->thread, NULL, &routine, philo))
		safe_process_exit(philo, THREAD_CREATE_FAIL);
	if (pthread_create(&philo->monitor, NULL, &monitor, philo))
		safe_process_exit(philo, THREAD_CREATE_FAIL);
	pthread_join(philo->thread, NULL);
	pthread_join(philo->monitor, NULL);
	safe_process_exit(philo, EXIT_SUCCESS);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	safe_print(philo, "is thinking");
	if (ft_usleep(philo->initial_thinking_time, philo) == false)
		return (NULL);
	while (true)
	{
		if (eating(philo) == false)
			break ;
		if (sleeping(philo) == false)
			break ;
		if (thinking(philo) == false)
			break ;
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	sem_wait(philo->sems.dead);
	sem_post(philo->sems.dead);
	sem_wait(philo->sems.check_status);
	philo->running = false;
	sem_post(philo->sems.check_status);
	i = -1;
	while (++i < philo->count)
		sem_post(philo->sems.dead);
	i = -1;
	while (++i < philo->count)
		sem_post(philo->sems.full);
	return (NULL);
}

void	*full_monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = -1;
	while (++i < data->count)
		sem_wait(data->sems.full);
	i = -1;
	while (++i < data->count)
		sem_post(data->sems.dead);
	return (NULL);
}

bool	is_running(t_philo *philo)
{
	bool	running;

	sem_wait(philo->sems.check_status);
	running = philo->running;
	sem_post(philo->sems.check_status);
	return (running);
}
