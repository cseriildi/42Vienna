/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:02:03 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/14 12:38:53 by cseriildii       ###   ########.fr       */
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

void	safe_exit(t_data *data, int exit_code)
{
	if (data)
	{
		safe_close_sem(data->sems.forks, "/forks");
		safe_close_sem(data->sems.full, "/full");
		safe_close_sem(data->sems.dead, "/dead");
		safe_close_sem(data->sems.print, "/print");
		safe_close_sem(data->sems.check_status, "/status");
		if (data->pids)
			free(data->pids);
		free(data);
	}
	print_error(exit_code);
	exit (exit_code);
}

void	safe_process_exit(t_philo *philo, int exit_code)
{
	if (philo)
	{
		safe_close_sem(philo->sems.forks, "/forks");
		safe_close_sem(philo->sems.full, "/full");
		safe_close_sem(philo->sems.dead, "/dead");
		safe_close_sem(philo->sems.print, "/print");
		safe_close_sem(philo->sems.check_status, "/status");
		free(philo);
	}
	exit (exit_code);
}
