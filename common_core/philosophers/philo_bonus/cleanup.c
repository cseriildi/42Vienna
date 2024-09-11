/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:02:03 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/11 19:59:23 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	int	i;

	if (data)
	{
		i = 0;
		while (data->sems.dead && i++ <= data->count)
			sem_post(data->sems.dead);
		i = 0;
		while (data->sems.full && i++ <= data->count)
			sem_post(data->sems.full);	
		safe_close_sem(data->sems.forks, "/forks");
		safe_close_sem(data->sems.full, "/full");
		safe_close_sem(data->sems.dead, "/dead");
		safe_close_sem(data->sems.print, "/print");
		safe_close_sem(data->sems.check_status, "/status");
		safe_close_sem(data->sems.program, "/program");
		safe_close_sem(data->sems.take2forks, "/take2forks");
		if (data->pids)
		{
			wait_processes(data);
			free(data->pids);
		}
		free(data);
	}
	print_error(exit_code);
	exit (exit_code);
}

void	safe_process_exit(t_philo *philo, int exit_code)
{
	if (philo)
	{
		death_alert((philo->sems), philo->count);
		safe_close_sem(philo->sems.forks, "/forks");
		safe_close_sem(philo->sems.full, "/full");
		safe_close_sem(philo->sems.dead, "/dead");
		safe_close_sem(philo->sems.print, "/print");
		safe_close_sem(philo->sems.check_status, "/status");
		safe_close_sem(philo->sems.program, "/program");
		safe_close_sem(philo->sems.take2forks, "/take2forks");
		free(philo);
	}
	exit (exit_code);
}

void	safe_close_sem(sem_t *sem, char *name)
{
	if (sem)
	{
		sem_unlink(name);
		sem_close(sem);
		sem = NULL;
	}
}

void	death_alert(sem_t sems, int count)
{
	int	i;

	i = 0;
	while (sems.dead && i++ <= count)
			sem_post(sems->dead);
	i = 0;
	while (sems->full && i++ <= count)
			sem_post(sems->full);
}