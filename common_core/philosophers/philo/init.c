/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:59:38 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/05 19:24:37 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, int argc, char **argv)
{
	data->philos = NULL;
	data->forks = NULL;
	data->print = NULL;
	data->program = NULL;
	data->running = true;
	data->handcuffs = NULL;
	if (init_input(data, argc, argv) != 0)
		return (EXIT_FAILURE);
	if (init_mutexes(data) != 0)
		return (EXIT_FAILURE);
	data->print = malloc(sizeof(pthread_mutex_t));
	if (!data->print)
		return (set_exit_code(data, MALLOC_FAIL));
	if (pthread_mutex_init(data->print, NULL) != 0)
		return (set_exit_code(data, MUTEX_INIT_FAIL));
	data->program = malloc(sizeof(pthread_mutex_t));
	if (!data->program)
		return (set_exit_code(data, MALLOC_FAIL));
	if (pthread_mutex_init(data->program, NULL) != 0)
		return (set_exit_code(data, MUTEX_INIT_FAIL));
	data->philos = malloc(sizeof(t_philo) * data->count);
	if (!data->philos)
		return (set_exit_code(data, MALLOC_FAIL));
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
			|| (i == 1 && ft_atoi(argv[i]) == 0))
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

	data->forks = malloc(sizeof(pthread_mutex_t) * data->count);
	if (!data->forks)
		return (set_exit_code(data, MALLOC_FAIL));
	data->handcuffs = malloc(sizeof(pthread_mutex_t) * data->count);
	if (!data->handcuffs)
		return (destroy_mutexes(data->forks, 0), set_exit_code(data, MALLOC_FAIL));
	i = -1;
	while (++i < data->count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			destroy_mutexes(data->forks, i);
			return (set_exit_code(data, MUTEX_INIT_FAIL));
		}
		if (pthread_mutex_init(&data->handcuffs[i], NULL) != 0)
		{
			destroy_mutexes(data->forks, i + 1);
			destroy_mutexes(data->handcuffs, i);
			return (set_exit_code(data, MUTEX_INIT_FAIL));
		}
		pthread_mutex_lock(&data->handcuffs[i]);
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
		if (philos[i].id % 2 == 0)
			philos[i].type = EVEN;
		else if (philos[i].id == data->count && philos[i].id != 1)
			philos[i].type = ODD_ONE_OUT;
		else
			philos[i].type = ODD;
		philos[i].times_eaten = 0;
		philos[i].last_eating_time = 0;
		philos[i].data = data;
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[(i + 1) % data->count];
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]))
			return (set_exit_code(data, THREAD_CREATE_FAIL));
	}
	return (EXIT_SUCCESS);
}

int	init_reaper_and_waiter(t_data *data)
{
	if (pthread_create(&data->waiter, NULL, &waiter, data))
		return (set_exit_code(data, THREAD_CREATE_FAIL));
	if (pthread_create(&data->reaper, NULL, &kill_starver, data))
		return (set_exit_code(data, THREAD_CREATE_FAIL));
	return (EXIT_SUCCESS);
}