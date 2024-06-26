/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:16:59 by icseri            #+#    #+#             */
/*   Updated: 2024/06/26 11:43:03 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*data;
	int		exit_code;

	exit_code = 0;
	data = malloc(sizeof(t_philo));
	if (!data)
		return (print_error(MALLOC_FAIL), MALLOC_FAIL);
	exit_code = check_input(argc, argv, data);
	if (exit_code != 0)
		return (exit_code);
	parsing(argc, argv, data);
	init_forks(data);
	exit_code = init_philos(data);
	if (exit_code != 0)
		return (exit_code);
	destroy_forks(data);
	return (0);
}
