/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:02:03 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/14 08:47:35 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

void	print_error(int code)
{
	if (code == MALLOC_FAIL)
		ft_putendl_fd("Memory allocation failed", 2);
	else if (code == MISUSE)
		ft_putendl_fd("./philo count die eat sleep [eat_count]", 2);
	else if (code == INCORRECT_INPUT)
		ft_putendl_fd("Min 1 philo, and the times/count positive integers", 2);
	else if (code == FORK_FAIL)
		ft_putendl_fd("Fork failed", 2);
	else if (code == SEM_FAIL)
		ft_putendl_fd("Semaphore failed", 2);
}

void	kill_processes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->count)
	{
		if (data->philos[i].pid != -1)
		{
			kill(data->philos[i].pid, SIGKILL);
			data->philos[i].pid = -1;
		}
	}
}

void	safe_exit(t_data *data, int exit_code)
{
	if (data)
	{
		if (data->philos)
		{
			kill_processes(data);
			free(data->philos);
		}
		safe_close_sem(data->forks, "/forks");
		safe_close_sem(data->full, "/full");
		safe_close_sem(data->dead, "/dead");
		safe_close_sem(data->print, "/print");
		free(data);
	}
	print_error(exit_code);
	exit (exit_code);
}

void	safe_process_exit(t_inprocess_data data, int exit_code)
{
	(void)data;
	/*if (data.forks)
	{
		sem_close(data.forks);
		sem_unlink("/forks");
	}
	if (data.full)
	{
		sem_close(data.full);
		sem_unlink("/full");
	}
	if (data.dead)
	{
		sem_close(data.dead);
		sem_unlink("/dead");
	}
	if (data.print)
	{
		sem_close(data.print);
		sem_unlink("/print");
	}*/
	exit (exit_code);
}
