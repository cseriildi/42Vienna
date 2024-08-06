/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:37:27 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/06 17:41:03 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, long long time, char *act)
{
	pthread_mutex_lock(philo->data->print);
	if (is_alive(philo) == true)
		printf("%lld %d %s\n", time, philo->id, act);
	pthread_mutex_unlock(philo->data->print);
}

void	set_status(t_data *data, int id)
{
	int	i;

	pthread_mutex_lock(data->check_status);
	data->running = false;
	pthread_mutex_lock(data->philos[id - 1].check_status);
	data->philos[id - 1].status = DEAD;
	pthread_mutex_unlock(data->philos[id - 1].check_status);
	pthread_mutex_lock(data->print);
	printf("%lld %d died\n", get_elapsed_time(data), id);
	pthread_mutex_unlock(data->print);
	i = -1;
	while (++i < data->count)
	{
		pthread_mutex_lock(data->philos[i].check_status);
		if (data->philos[i].status != DEAD)
			data->philos[i].status = MOURNING;
		pthread_mutex_unlock(data->philos[i].check_status);
	}
	pthread_mutex_unlock(data->check_status);
}

bool	check_if_all_full(t_data *data, int id)
{
	int	i;

	if (data->min_eat_count == -1)
		return (false);
	i = -1;
	while (++i < data->count)
	{
		if (i == id - 1)
			continue ;
		pthread_mutex_lock(data->philos[i].check_status);
		if (data->philos[i].status != FULL)
		{
			pthread_mutex_unlock(data->philos[i].check_status);
			return (false);
		}
		pthread_mutex_unlock(data->philos[i].check_status);
	}
	pthread_mutex_lock(data->check_status);
	data->running = false;
	pthread_mutex_unlock(data->check_status);
	return (true);
}

int	get_type(int id, int count)
{
	if (id % 2 == 0)
		return (EVEN);
	else if (id == count && id != 1)
		return (ODD_ONE_OUT);
	else
		return (ODD);
}

int	mutex_init(t_data *data, pthread_mutex_t **mutex)
{
	*mutex = malloc(sizeof(pthread_mutex_t));
	if (!*mutex)
		return (set_exit_code(data, MALLOC_FAIL));
	if (pthread_mutex_init(*mutex, NULL) != 0)
	{
		free(*mutex);
		*mutex = NULL;
		return (set_exit_code(data, MUTEX_INIT_FAIL));
	}
	return (EXIT_SUCCESS);
}
