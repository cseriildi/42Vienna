/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:56:18 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/11 14:56:36 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_input(int argc, char **argv)
{
	int		i;
	char	*tmp;

	if (argc < 5 || argc > 6)
		safe_exit(NULL, MISUSE);
	i = 0;
	while (++i < argc)
	{
		tmp = ft_itoa(ft_atoi(argv[i]));
		if (!tmp)
			safe_exit(NULL, MALLOC_FAIL);
		if (ft_strcmp(argv[i], tmp) != 0 || ft_atoi(argv[i]) < 0
			|| (i == 1 && ft_atoi(argv[i]) <= 0))
		{
			free(tmp);
			safe_exit(NULL, INCORRECT_INPUT);
		}
		free(tmp);
	}
	if (argc == 6 && ft_atoi(argv[5]) == 0)
		safe_exit(NULL, EXIT_SUCCESS);
}

int	wait_processes(t_data *data)
{
	int	i;
	int	status;
	int	exit_code;

	exit_code = 0;
	i = -1;
	while (++i < data->count)
	{
		if (data->pids[i] != -1)
		{
			waitpid(data->pids[i], &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
				exit_code = WEXITSTATUS(status);
		}
	}
	return (exit_code);
}

void	safe_print(t_philo *philo, char *str)
{
	sem_wait(philo->sems.print);
	if (is_running(philo) == true)
		printf("%lld %d %s\n",
			get_elapsed_time(philo->start_time), philo->id, str);
	sem_post(philo->sems.print);
}

sem_t	*safe_open_sem(char *name, int value)
{
	sem_t	*sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (sem == SEM_FAILED)
		return (SEM_FAILED);
	sem_unlink(name);
	return (sem);
}

bool	is_running(t_philo *philo)
{
	bool	running;

	sem_wait(philo->sems.check_status);
	running = philo->running;
	sem_post(philo->sems.check_status);
	return (running);
}
