/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:20:04 by icseri            #+#    #+#             */
/*   Updated: 2024/06/25 10:16:57 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum s_err
{
	MALLOC_FAIL = 2,
	WRONG_INPUT,
	THREAD_CREATE_FAIL,
	THREAD_JOIN_FAIL
}	t_err;

typedef struct s_philo
{
	pthread_t		*philos;
	pthread_mutex_t	mutex;
	int				count;
}	t_philo;

void	safe_exit(t_philo *data, int error_code);

#endif