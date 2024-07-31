/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:59:38 by cseriildii        #+#    #+#             */
/*   Updated: 2024/07/30 16:56:22 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_data(t_data *data, int argc, char **argv)
{
	data->start_time = get_time();
	data->philos = NULL;
	data->forks = NULL;
	data->print_lock = NULL;
	if (init_input(data, argc, argv) != 0)
		return (EXIT_FAILURE);
	if (init_forks(data) != 0)
		return (EXIT_FAILURE);
	if (init_philos(data) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(data->print_lock, NULL) != 0)
		return (set_exit_code(data, MUTEX_INIT_FAIL));
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

int	init_forks(t_data *data)
{
	int			i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->count);
	if (!data->forks)
		return (set_exit_code(data, MALLOC_FAIL));
	i = -1;
	while (++i < data->count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			data->forks = NULL;
			return (set_exit_code(data, MUTEX_INIT_FAIL));
		}
	}
	return (EXIT_SUCCESS);
}

int	init_philos(t_data *data)
{
	int	i;
	int	count;

	count = data->count;
	data->philos = malloc(sizeof(t_philo) * count);
	if (!data->philos)
		return (set_exit_code(data, MALLOC_FAIL));
	i = -1;
	while (++i < count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].times_eaten = 0;
		data->philos[i].last_eating_time = 0;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % count];
		if (pthread_create(&data->philos[i].thread, NULL, routine, &data->philos[i]) != 0)
			return (set_exit_code(data, THREAD_CREATE_FAIL));
	}
	return (EXIT_SUCCESS);
}

