/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:10:49 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/06 17:26:04 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

int	print_error(int code)
{
	if (code == MALLOC_FAIL)
		ft_putendl_fd("Memory allocation failed", 2);
	else if (code == MISUSE)
		ft_putendl_fd("./philo count die eat sleep [eat_count]", 2);
	else if (code == INCORRECT_INPUT)
		ft_putendl_fd("Min 1 philo, and the times/count positive integers", 2);
	else if (code == THREAD_CREATE_FAIL)
		ft_putendl_fd("Thread creation failed", 2);
	else if (code == MUTEX_INIT_FAIL)
		ft_putendl_fd("Mutex initialization failed", 2);
	return (code);
}

void	destroy_mutexes(pthread_mutex_t *mutexes, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		pthread_mutex_destroy(&mutexes[i]);
	free(mutexes);
	mutexes = NULL;
}

int	free_data(t_data *data)
{
	int	exit_code;

	if (data)
	{
		exit_code = print_error(data->exit_code);
		if (data->forks)
			destroy_mutexes(data->forks, data->count);
		if (data->philos)
		{
			free(data->philos);
			data->philos = NULL;
		}
		if (data->philo_lock)
			destroy_mutexes(data->philo_lock, data->count);
		if (data->check_status)
			destroy_mutexes(data->check_status, 1);
		if (data->print)
			destroy_mutexes(data->print, 1);
		if (data->program)
			destroy_mutexes(data->program, 1);
		free(data);
		return (exit_code);
	}
	return (EXIT_SUCCESS);
}

int	set_exit_code(t_data *data, int code)
{
	data->exit_code = code;
	return (code);
}
