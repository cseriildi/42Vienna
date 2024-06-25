/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:20:04 by icseri            #+#    #+#             */
/*   Updated: 2024/06/25 17:01:04 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

typedef enum s_err
{
	MALLOC_FAIL = 2,
	MISUSE,
	INCORRECT_INPUT,
	THREAD_CREATE_FAIL,
	THREAD_JOIN_FAIL
}	t_err;

typedef struct s_philo
{
	pthread_t		*philos;
	pthread_mutex_t	mutex;
	int				count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	bool			min_eat;
	int				eat_count;
	int				err;
}	t_philo;

//utils
int		ft_atoi(const char *nptr);
char	*ft_itoa(int nb);
int		ft_strcmp(char *s1, char *s2);
void	print_error(int code);
void	free_data(t_philo *data, int code);

#endif