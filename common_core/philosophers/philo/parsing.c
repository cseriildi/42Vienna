/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:48:29 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/26 09:12:33 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(int argc, char **argv, t_philo *data)
{
	int		i;
	char	*tmp;

	data->err = 0;
	if (argc < 5 || argc > 6)
		return (free_data(data, MISUSE), data->err);
	i = 0;
	while (++i < argc)
	{
		tmp = ft_itoa(ft_atoi(argv[i]));
		if (!tmp)
			return (free_data(data, MALLOC_FAIL), data->err);
		if (ft_strcmp(argv[i], tmp) != 0 || ft_atoi(argv[i]) < 0
			|| (i == 1 && ft_atoi(argv[i]) == 0))
			return (free(tmp), free_data(data, INCORRECT_INPUT), data->err);
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
