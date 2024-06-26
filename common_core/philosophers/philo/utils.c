/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:10:49 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/26 11:39:30 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(int code)
{
	if (code == MALLOC_FAIL)
		write(2, "Memory allocation failed\n", 26);
	else if (code == MISUSE)
		write(2, "./philo count die eat sleep [eat_count]\n", 41);
	else if (code == INCORRECT_INPUT)
		write(2, "Min 1 philo, and the times/count positive integers \n", 53);
	else if (code == THREAD_CREATE_FAIL)
		write(2, "Thread creation failed\n", 24);
	else if (code == THREAD_JOIN_FAIL)
		write(2, "Thread joining failed\n", 23);
	else if (code == MUTEX_INIT_FAIL)
		write(2, "Mutex initialization failed\n", 29);
}

void	destroy_forks(t_philo *data)
{
	int			i;

	i = -1;
	while (++i < data->count)
		pthread_mutex_destroy(&data->forks[i]);
	data->forks = NULL;
}

void	free_data(t_philo *data, int code)
{
	print_error(code);
	if (data)
	{
		if (data->philos)
			free(data->philos);
		if (data->forks)
			destroy_forks(data);
		free(data);
	}
}
