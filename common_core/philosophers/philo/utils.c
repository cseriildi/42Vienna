/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:10:49 by cseriildii        #+#    #+#             */
/*   Updated: 2024/07/31 14:07:09 by icseri           ###   ########.fr       */
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
	else if (code == THREAD_JOIN_FAIL)
		ft_putendl_fd("Thread joining failed", 2);
	else if (code == MUTEX_INIT_FAIL)
		ft_putendl_fd("Mutex initialization failed", 2);
	return (code);
}

void	destroy_forks(t_data *data)
{
	int			i;

	i = -1;
	while (++i < data->count)
		pthread_mutex_destroy(&data->forks[i]);
	free(data->forks);
	data->forks = NULL;
}

int	free_data(t_data *data)
{
	int	exit_code;

	if (data)
	{
		exit_code = print_error(data->exit_code);
		if (data->philos)
		{
			free(data->philos);
			data->philos = NULL;
		}
		if (data->forks)
			destroy_forks(data);
		if (data->print_lock)
		{
			pthread_mutex_destroy(data->print_lock);
			free(data->print_lock);
			data->print_lock = NULL;
		}
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
