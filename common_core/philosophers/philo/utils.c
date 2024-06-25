/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:10:49 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/25 17:00:39 by icseri           ###   ########.fr       */
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
}

void	free_data(t_philo *data, int code)
{
	data->err = code;
	print_error(data->err);
	if (data)
	{
		if (data->philos)
			free(data->philos);
		if (data->count > 0)
			pthread_mutex_destroy(&data->mutex);
		free(data);
	}
}
