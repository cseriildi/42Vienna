/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:55:05 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/13 14:51:42 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_data(t_data *data, int argc, char **argv)
{
	int	i;

	data->argc = argc;
	data->argv = argv;
	data->count = ft_atoi(argv[1]);
	data->sems.forks = NULL;
	data->sems.take2forks = NULL;
	data->sems.full = NULL;
	data->sems.dead = NULL;
	data->sems.print = NULL;
	data->sems.check_status = NULL;
	data->sems.program = NULL;
	data->dead_monitor = 0;
	data->full_monitor = 0;
	data->pids = malloc(sizeof(pid_t) * data->count);
	if (!data->pids)
		safe_exit(data, MALLOC_FAIL);
	i = -1;
	while (++i < data->count)
		data->pids[i] = -1;
}

void	init_philo(t_philo *philo, int i, t_data *data)
{
	philo->id = i + 1;
	philo->count = data->count;
	philo->time_to_die = ft_atoi(data->argv[2]);
	philo->time_to_eat = ft_atoi(data->argv[3]);
	philo->time_to_sleep = ft_atoi(data->argv[4]);
	philo->min_eat_count = -1;
	if (data->argc == 6)
		philo->min_eat_count = ft_atoi(data->argv[5]);
	philo->time_to_think = philo->time_to_eat - philo->time_to_sleep;
	if (philo->count % 2 == 1 && philo->count != 1)
		philo->time_to_think += philo->time_to_eat / (float)(philo->count / 2);
	philo->initial_thinking_time = 0;
	if (philo->count % 2 == 0)
		philo->initial_thinking_time = philo->time_to_eat
			* (i >= philo->count / 2);
	else if (philo->count != 1)
		philo->initial_thinking_time = philo->time_to_eat
			/ (float)(philo->count / 2) * i;
	philo->eat_count = 0;
	philo->running = true;
	philo->start_time = data->start_time;
	philo->last_eating_time = philo->start_time;
	philo->sems = data->sems;
	free(data->pids);
	free(data);
}

void	init_processes(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * data->count);
	if (!philo)
		safe_exit(data, MALLOC_FAIL);
	i = -1;
	while (++i < data->count)
	{
		data->pids[i] = fork();
		if (data->pids[i] == -1)
		{
			free(philo);
			safe_exit(data, FORK_FAIL);
		}
		else if (data->pids[i] == 0)
		{
			init_philo(philo, i, data);
			simulation(philo);
		}
	}
	free(philo);
}

void	init_semaphores(t_data *data)
{
	data->sems.forks = safe_open_sem("/forks", data->count);
	if (data->sems.forks == SEM_FAILED)
		safe_exit(data, SEM_FAIL);
	data->sems.full = safe_open_sem("/full", 0);
	if (data->sems.full == SEM_FAILED)
		safe_exit(data, SEM_FAIL);
	data->sems.dead = safe_open_sem("/dead", 0);
	if (data->sems.dead == SEM_FAILED)
		safe_exit(data, SEM_FAIL);
	data->sems.print = safe_open_sem("/print", 1);
	if (data->sems.print == SEM_FAILED)
		safe_exit(data, SEM_FAIL);
	data->sems.check_status = safe_open_sem("/status", 1);
	if (data->sems.check_status == SEM_FAILED)
		safe_exit(data, SEM_FAIL);
	data->sems.program = safe_open_sem("/program", 0);
	if (data->sems.program == SEM_FAILED)
		safe_exit(data, SEM_FAIL);
	data->sems.take2forks = safe_open_sem("/take2forks", data->count / 2);
	if (data->sems.take2forks == SEM_FAILED)
		safe_exit(data, SEM_FAIL);
}

void	init_threads(t_data *data)
{
	if (pthread_create(&data->dead_monitor, NULL, &dead_monitor, data))
		safe_exit(data, THREAD_CREATE_FAIL);
	if (pthread_create(&data->full_monitor, NULL, &full_monitor, data))
	{
		pthread_join(data->dead_monitor, NULL);
		safe_exit(data, THREAD_CREATE_FAIL);
	}
	pthread_join(data->dead_monitor, NULL);
	pthread_join(data->full_monitor, NULL);
}
