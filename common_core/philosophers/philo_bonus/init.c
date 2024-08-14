/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:55:05 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/14 12:48:18 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_data(t_data *data, char **argv)
{
	data->count = ft_atoi(argv[1]);
	data->pids = malloc(sizeof(pid_t) * data->count);
	if (!data->pids)
		safe_exit(data, MALLOC_FAIL);
	data->pids = memset(data->pids, -1, sizeof(pid_t) * data->count);
}

void	init_philo(t_philo *philo, int i, int argc, char **argv)
{
	philo->id = i + 1;
	philo->count = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->min_eat_count = -1;
	if (argc == 6)
		philo->min_eat_count = ft_atoi(argv[5]);
	philo->time_to_think = philo->time_to_eat - philo->time_to_sleep;
	if (philo->count % 2 == 1)
		philo->time_to_think += philo->time_to_eat / (float)(philo->count / 2);
	if (philo->count % 2 == 0)
		philo->initial_thinking_time = philo->time_to_eat
			* (i >= philo->count / 2);
	else
		philo->initial_thinking_time = philo->time_to_eat
			/ (float)(philo->count / 2) * i;
	philo->eat_count = 0;
	philo->running = true;
}

void	init_processes(t_data *data, int argc, char **argv)
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
			init_philo(philo, i, argc, argv);
			philo->sems = data->sems;
			free(data->pids);
			free(data);
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
	data->sems.print = safe_open_sem("/print", 0);
	if (data->sems.print == SEM_FAILED)
		safe_exit(data, SEM_FAIL);
	data->sems.check_status = safe_open_sem("/status", 1);
	if (data->sems.check_status == SEM_FAILED)
		safe_exit(data, SEM_FAIL);
}

void	init_threads(t_data *data)
{
	pthread_create(&data->full_monitor, NULL, &full_monitor, data);
	pthread_join(data->full_monitor, NULL);
}
