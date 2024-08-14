/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:38:52 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/13 21:30:41 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*dead_monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	sem_wait(data->dead);
	kill_processes(data);
	i = -1;
	while (++i < data->count)
		sem_post(data->full);
	return (NULL);
}

void	*full_monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = -1;
	while (++i < data->count)
		sem_wait(data->full);
	sem_post(data->dead);
	return (NULL);
}
