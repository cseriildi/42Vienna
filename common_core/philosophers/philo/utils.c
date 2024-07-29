/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:10:49 by cseriildii        #+#    #+#             */
/*   Updated: 2024/07/29 13:53:42 by icseri           ###   ########.fr       */
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

int	free_data(t_philo *data)
{
	int exit_code;

	exit_code = data->exit_code;
	print_error(data->exit_code);
	if (data)
	{
		if (data->philos)
			free(data->philos);
		if (data->forks)
			destroy_forks(data);
		free(data);
	}
	return (exit_code);
}


long	*get_time(void)
{
	struct timeval	tv;
	long			*milliseconds;
	
	milliseconds = malloc(sizeof(long));
	if (!milliseconds)
		return (NULL);
	gettimeofday(&tv, NULL);
	*milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}