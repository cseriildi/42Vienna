/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:20:04 by icseri            #+#    #+#             */
/*   Updated: 2024/08/06 19:58:39 by cseriildii       ###   ########.fr       */
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
	MUTEX_INIT_FAIL
}	t_err;

typedef enum s_status
{
	ALIVE,
	DEAD,
	FULL,
	MOURNING
}	t_status;

typedef enum s_type
{
	ODD_ONE_OUT,
	EVEN,
	ODD
}	t_type;

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				type;
	int				status;
	int				times_eaten;
	long long		last_eating_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*check_status;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_eat_count;
	long long		start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*program;
	pthread_mutex_t	*philo_lock;
	pthread_mutex_t	*check_status;
	pthread_t		monitor;
	int				exit_code;
	bool			running;
}	t_data;

//init
int			init_data(t_data *data, int argc, char **argv);
int			init_input(t_data *data, int argc, char **argv);
int			init_philos(t_data *data, t_philo *philos);
int			init_mutexes(t_data *data);
int			init_monitor(t_data *data);

//routine
void		*routine(void *arg);
void		*monitoring(void *arg);
void		join_threads(t_data *data);
bool		is_running(t_data *data);
bool		is_alive(t_philo *philo);

//events
bool		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
bool		take_forks(t_philo *philo);
void		release_forks(t_philo *philo);

//time 
long long	get_time(void);
long long	get_elapsed_time(t_data *data);
long long	get_time_left(t_data *data);
void		ft_usleep(long long time, t_data *data);

//libft
int			ft_atoi(const char *nptr);
char		*ft_itoa(int nb);
int			ft_strcmp(char *s1, char *s2);

//utils	
void		print_status(t_philo *philo, char *act);
void		set_status(t_data *data, int id);
bool		check_if_all_full(t_data *data, int id);
int			get_type(int id, int count);
int			mutex_init(t_data *data, pthread_mutex_t **mutex);

//cleanup
int			set_exit_code(t_data *data, int code);
int			print_error(int code);
void		destroy_mutexes(pthread_mutex_t *mutexes, int count);
int			free_data(t_data *data);

#endif