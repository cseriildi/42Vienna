/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:10:49 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/25 10:41:24 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


char	*error_message(int code)
{
	if (code == EXIT_FAILURE)
		return ("General error");
	else if (code == MALLOC_FAIL)
		return ("Memory allocation failed");
	else if (code == WRONG_INPUT)
		return ("Wrong input");
	else if (code == THREAD_CREATE_FAIL)
		return ("Thread creation failed");
	else if (code == THREAD_JOIN_FAIL)
		return ("Thread joining failed");
	else
		return ("Unknown error");
}

void	safe_exit(t_philo *data, int error_code)
{
	if (error_code != 0)
		perror(error_message(error_code));
	if (data)
	{
		if (data->philos)
			free(data->philos);
		if (data->mutex)
			pthread_mutex_destroy(&data->mutex);
		free(data);
	}
	exit(error_code);
}
