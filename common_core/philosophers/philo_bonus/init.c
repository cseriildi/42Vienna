/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:55:05 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/14 08:55:19 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_data(t_data *data, int argc, char **argv)
{
	data->count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->time_to_think = data->time_to_eat - data->time_to_sleep;
	if (data->count % 2 == 1)
		data->time_to_think += data->time_to_eat / (float)(data->count / 2);
	data->min_eat_count = -1;
	if (argc == 6)
		data->min_eat_count = ft_atoi(argv[5]);
	data->philos = malloc(sizeof(t_philo) * data->count);
	if (!data->philos)
		safe_exit(data, MALLOC_FAIL);
	init_philos(data);
}

void	init_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->count)
	{
		data->philos[i].id = i + 1;
		if (data->count % 2 == 0)
			data->philos[i].initial_thinking_time = data->time_to_eat
				* (i >= data->count / 2);
		else
			data->philos[i].initial_thinking_time = data->time_to_eat
				/ (float)(data->count / 2) * i;
		data->philos[i].pid = -1;
		data->philos[i].data = data;
	}
}

void	init_processes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->count)
	{
		data->philos[i].pid = fork();
		if (data->philos[i].pid == -1)
			safe_exit(data, FORK_FAIL);
		else if (data->philos[i].pid == 0)
		{
			simulation(&data->philos[i]);
		}
	}
}

void	init_semaphores(t_data *data)
{
	sem_unlink("/forks");
	data->sems.forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, data->count);
	if (data->sems.forks == SEM_FAILED)
		safe_exit(data, SEM_FAIL);
	sem_unlink("/forks");
	sem_unlink("/full");
	data->sems.full = sem_open("/full", O_CREAT | O_EXCL, 0644, 0);
	if (data->sems.full == SEM_FAILED)
		safe_exit(data, SEM_FAIL);
	sem_unlink("/full");
	sem_unlink("/dead");
	data->sems.dead = sem_open("/dead", O_CREAT | O_EXCL, 0644, 0);
	if (data->sems.dead == SEM_FAILED)
		safe_exit(data, SEM_FAIL);
	sem_unlink("/dead");
	sem_unlink("/print");
	data->sems.print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	if (data->sems.print == SEM_FAILED)
		safe_exit(data, SEM_FAIL);
	sem_unlink("/print");
}

void	init_threads(t_data *data)
{
	pthread_create(&data->dead_monitor, NULL, &dead_monitor, data);
	pthread_create(&data->full_monitor, NULL, &full_monitor, data);
	pthread_join(data->dead_monitor, NULL);
	pthread_join(data->full_monitor, NULL);
}
