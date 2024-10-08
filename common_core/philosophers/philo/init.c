/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:59:38 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/13 13:09:18 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, int argc, char **argv)
{
	data->running = true;
	if (init_input(data, argc, argv) != 0)
		return (EXIT_FAILURE);
	if (mutex_init(data, &data->print) != 0)
		return (EXIT_FAILURE);
	if (mutex_init(data, &data->program) != 0)
		return (EXIT_FAILURE);
	if (mutex_init(data, &data->check_status) != 0)
		return (EXIT_FAILURE);
	if (init_mutexes(data) != 0)
		return (EXIT_FAILURE);
	data->philos = ft_calloc(sizeof(t_philo), data->count);
	if (!data->philos)
		return (set_exit_code(data, MALLOC_FAIL));
	data->time_to_think = data->time_to_eat - data->time_to_sleep;
	if (data->count % 2 == 1 && data->count != 1)
		data->time_to_think += data->time_to_eat / (float)(data->count / 2);
	return (EXIT_SUCCESS);
}

int	init_input(t_data *data, int argc, char **argv)
{
	int		i;
	char	*tmp;

	if (argc < 5 || argc > 6)
		return (set_exit_code(data, MISUSE));
	i = 0;
	while (++i < argc)
	{
		tmp = ft_itoa(ft_atoi(argv[i]));
		if (!tmp)
			return (set_exit_code(data, MALLOC_FAIL));
		if (ft_strcmp(argv[i], tmp) != 0 || ft_atoi(argv[i]) < 0
			|| (i == 1 && ft_atoi(argv[i]) <= 0))
			return (free(tmp), set_exit_code(data, INCORRECT_INPUT));
		free(tmp);
	}
	data->count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->min_eat_count = -1;
	if (argc == 6)
		data->min_eat_count = ft_atoi(argv[5]);
	return (set_exit_code(data, EXIT_SUCCESS));
}

int	init_mutexes(t_data *data)
{
	int			i;

	data->forks = ft_calloc(sizeof(pthread_mutex_t), data->count);
	if (!data->forks)
		return (set_exit_code(data, MALLOC_FAIL));
	i = -1;
	while (++i < data->count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (destroy_mutexes(data->forks, i),
				set_exit_code(data, MUTEX_INIT_FAIL));
	}
	data->philo_lock = ft_calloc(sizeof(pthread_mutex_t), data->count);
	if (!data->philo_lock)
		return (set_exit_code(data, MALLOC_FAIL));
	i = -1;
	while (++i < data->count)
	{
		if (pthread_mutex_init(&data->philo_lock[i], NULL) != 0)
			return (destroy_mutexes(data->philo_lock, i),
				set_exit_code(data, MUTEX_INIT_FAIL));
	}
	return (EXIT_SUCCESS);
}

int	init_philos(t_data *data, t_philo *philos)
{
	int		i;

	i = -1;
	while (++i < data->count)
	{
		philos[i].id = i + 1;
		if (data->count % 2 == 0 && i % 2 == 1)
			philos[i].initial_thinking_time = data->time_to_eat;
		else if (data->count % 2 == 0 && i % 2 == 0)
			philos[i].initial_thinking_time = 0;
		else if (data->count % 2 == 1 && data->count != 1)
			philos[i].initial_thinking_time = data->time_to_eat * (i % 2 == 1)
				+ data->time_to_eat / (float)(data->count / 2) * (i / 2);
		philos[i].times_eaten = 0;
		philos[i].last_eating_time = 0;
		philos[i].status = ALIVE;
		philos[i].data = data;
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[(i + 1) % data->count];
		philos[i].check_status = &data->philo_lock[i];
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]))
			return (data->running = false, set_exit_code(data, THREAD_FAIL));
	}
	return (EXIT_SUCCESS);
}

int	init_monitor(t_data *data)
{
	if (pthread_create(&data->monitor, NULL, &monitoring, data))
	{
		data->running = false;
		return (set_exit_code(data, THREAD_FAIL));
	}
	return (EXIT_SUCCESS);
}
