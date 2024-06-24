/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:16:59 by icseri            #+#    #+#             */
/*   Updated: 2024/06/24 15:17:52 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *func()
{

}

int	main(int argc, char **argv)
{
	pthread_t	t1;

	if (pthread_create(&t1, NULL, &func, NULL) != 0)
		exit(1);
	if (pthread_join(t1, NULL) != 0)
		exit(2);
}