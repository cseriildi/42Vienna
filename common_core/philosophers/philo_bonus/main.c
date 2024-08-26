/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:22:50 by icseri            #+#    #+#             */
/*   Updated: 2024/08/26 14:40:09 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		exit_code;

	check_input(argc, argv);
	data = malloc(sizeof(t_data));
	if (!data)
		safe_exit(NULL, MALLOC_FAIL);
	init_data(data, argc, argv);
	init_semaphores(data);
	data->start_time = get_time();
	init_processes(data);
	init_threads(data);
	exit_code = wait_processes(data);
	safe_exit(data, exit_code);
}
