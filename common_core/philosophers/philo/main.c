/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:16:59 by icseri            #+#    #+#             */
/*   Updated: 2024/06/25 17:07:36 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func(void *arg)
{
	t_philo			*data;
	struct timeval	tv;
	long			milliseconds;

	data = (t_philo *)arg;
	pthread_mutex_lock(&data->mutex);
	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("%ld\n", milliseconds);
	pthread_mutex_unlock(&data->mutex);
	return (NULL);
}

int	init_philos(t_philo *data)
{
	int			i;

	data->err = 0;
	data->philos = malloc(sizeof(pthread_t) * data->count);
	if (!data->philos)
		return (free_data(data, MALLOC_FAIL), data->err);
	i = -1;
	while (++i < data->count)
	{
		if (pthread_create(&data->philos[i], NULL, func, data) != 0)
			return (free_data(data, THREAD_CREATE_FAIL), data->err);
	}
	i = -1;
	while (++i < data->count)
	{
		if (pthread_join(data->philos[i], NULL) != 0)
			return (free_data(data, THREAD_JOIN_FAIL), data->err);
	}
	return (data->err);
}

int	check_input(int argc, char **argv, t_philo *data)
{
	int		i;
	char	*tmp;

	data->err = 0;
	if (argc < 5 || argc > 6)
		return (free_data(data, MISUSE), data->err);
	i = 0;
	while (++i < argc)
	{
		tmp = ft_itoa(ft_atoi(argv[i]));
		if (!tmp)
			return (free_data(data, MALLOC_FAIL), data->err);
		if (ft_strcmp(argv[i], tmp) != 0 || ft_atoi(argv[i]) < 0
			|| (i == 1 && ft_atoi(argv[i]) == 0))
			return (free(tmp), free_data(data, INCORRECT_INPUT), data->err);
		free(tmp);
	}
	return (0);
}

void	parsing(int argc, char **argv, t_philo *data)
{
	data->count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->eat_count = 0;
	data->min_eat = false;
	if (argc == 6)
	{
		data->min_eat = true;
		data->eat_count = ft_atoi(argv[5]);
	}
}

int	main(int argc, char **argv)
{
	t_philo	*data;

	data = malloc(sizeof(t_philo));
	if (!data)
		return (print_error(MALLOC_FAIL), data->err);
	if (check_input(argc, argv, data) != 0)
		return (data->err);
	parsing(argc, argv, data);
	pthread_mutex_init(&data->mutex, NULL);
	if (init_philos(data) != 0)
		return (data->err);
	pthread_mutex_destroy(&data->mutex);
}
