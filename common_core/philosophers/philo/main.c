/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:16:59 by icseri            #+#    #+#             */
/*   Updated: 2024/07/29 14:13:40 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*data;
	int		exit_code;

	exit_code = 0;
	printf("%ld\n", *(long*)(get_time()));
	data = malloc(sizeof(t_philo));
	if (!data)
		return (print_error(MALLOC_FAIL), MALLOC_FAIL);
	exit_code = check_input(argc, argv, data);
	if (exit_code != 0)
		return (free_data(data));
	parsing(argc, argv, data);
	data->exit_code = init_forks(data);
	if (data->exit_code != 0)
		return (free_data(data));
	data->exit_code = init_philos(data);
	if (data->exit_code != 0)
		return (free_data(data));
	return (free_data(data));
}
