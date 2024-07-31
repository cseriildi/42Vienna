/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:20:04 by icseri            #+#    #+#             */
/*   Updated: 2024/07/30 16:58:56 by cseriildii       ###   ########.fr       */
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

struct s_data;

typedef struct s_philo
{
	int 			id;
	int				times_eaten;
	long			last_eating_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_eat_count;
	long			start_time;
	t_philo			*philos;
	pthread_mutex_t *forks;
	pthread_mutex_t *print_lock;
	int				exit_code;
}	t_data;

//init
int		init_data(t_data *data, int argc, char **argv);
int		init_input(t_data *data, int argc, char **argv);
int		init_philos(t_data *data);
int		init_forks(t_data *data);

//routine
void	*routine(void *arg);


//utils
int		print_error(int code);
int		free_data(t_data *data);
void	destroy_forks(t_data *data);
long	get_time(void);
int		set_exit_code(t_data *data, int code);

//libft
int		ft_atoi(const char *nptr);
char	*ft_itoa(int nb);
int		ft_strcmp(char *s1, char *s2);

#endif
