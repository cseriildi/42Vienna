/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:48:29 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/26 11:40:22 by icseri           ###   ########.fr       */
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
		return (free_data(data, MISUSE), MISUSE);
	i = 0;
	while (++i < argc)
	{
		tmp = ft_itoa(ft_atoi(argv[i]));
		if (!tmp)
			return (free_data(data, MALLOC_FAIL), MALLOC_FAIL);
		if (ft_strcmp(argv[i], tmp) != 0 || ft_atoi(argv[i]) < 0
			|| (i == 1 && ft_atoi(argv[i]) == 0))
			return (free(tmp), free_data(data, INCORRECT_INPUT), INCORRECT_INPUT);
		free(tmp);
	}
	return (0);
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
