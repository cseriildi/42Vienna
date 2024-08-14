/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:56:18 by cseriildii        #+#    #+#             */
/*   Updated: 2024/08/14 08:18:44 by cseriildii       ###   ########.fr       */
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
	int exit_code;

	exit_code = 0;
	i = -1;
	while (++i < data->count)
	{
		waitpid(data->philos[i].pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			exit_code = WEXITSTATUS(status);
	}
	return (exit_code);
}

void	safe_print(t_inprocess_data philo,  char *str)
{
	sem_wait(philo.print);
	printf("%lld %d %s\n", get_elapsed_time(philo.start_time), philo.id, str);
	sem_post(philo.print);
}

void	safe_close_sem(sem_t *sem, char *name)
{
	if (sem)
	{
		sem_close(sem);
		sem_unlink(name);
		sem = NULL;
	}
}
