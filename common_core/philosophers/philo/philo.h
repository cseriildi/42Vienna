/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:20:04 by icseri            #+#    #+#             */
/*   Updated: 2024/07/05 10:39:20 by icseri           ###   ########.fr       */
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
	THREAD_JOIN_FAIL,
	MUTEX_INIT_FAIL
}	t_err;

typedef struct s_philo
{
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	int				count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	bool			min_eat;
	int				eat_count;
}	t_philo;

//utils
void	print_error(int code);
void	free_data(t_philo *data, int code);
void	destroy_forks(t_philo *data);
long	*get_time(void);

//parsing
int		check_input(int argc, char **argv, t_philo *data);
void	parsing(int argc, char **argv, t_philo *data);

//init
int		init_philos(t_philo *data);
int		init_forks(t_philo *data);

//libft
int		ft_atoi(const char *nptr);
char	*ft_itoa(int nb);
int		ft_strcmp(char *s1, char *s2);

#endif
