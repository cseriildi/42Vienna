/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:48:29 by cseriildii        #+#    #+#             */
/*   Updated: 2024/07/29 14:14:28 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(int argc, char **argv, t_philo *data)
{
	int		i;
	char	*tmp;

	data->philos = NULL;
	data->forks = NULL;
	if (argc < 5 || argc > 6)
		return (MISUSE);
	i = 0;
	while (++i < argc)
	{
		tmp = ft_itoa(ft_atoi(argv[i]));
		if (!tmp)
			return (MALLOC_FAIL);
		if (ft_strcmp(argv[i], tmp) != 0 || ft_atoi(argv[i]) < 0
			|| (i == 1 && ft_atoi(argv[i]) == 0))
			return (free(tmp), INCORRECT_INPUT);
		free(tmp);
	}
	return (EXIT_SUCCESS);
}

void	parsing(int argc, char **argv, t_philo *data)
{
	data->count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->eat_count = 0;
	data->min_eat = false;
	if (argc == 6)
	{
		data->min_eat = true;
		data->eat_count = ft_atoi(argv[5]);
	}
}
