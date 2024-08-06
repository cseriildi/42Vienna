/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:20:04 by icseri            #+#    #+#             */
/*   Updated: 2024/08/06 10:40:08 by cseriildii       ###   ########.fr       */
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
	pthread_t		reaper;
	int				exit_code;
	bool			running;
}	t_data;

//init
int			init_data(t_data *data, int argc, char **argv);
int			init_input(t_data *data, int argc, char **argv);
int			init_philos(t_data *data, t_philo *philos);
int			init_mutexes(t_data *data);
int			init_reaper(t_data *data);

//routine
void		*routine(void *arg);
void		*kill_starver(void *arg);

//time 
long long	get_time(void);
long long	get_elapsed_time(t_data *data);
void		ft_usleep(long long time, t_data *data);

//utils
int			print_error(int code);
int			free_data(t_data *data);
void		destroy_mutexes(pthread_mutex_t *mutexes, int count);
int			set_exit_code(t_data *data, int code);

//utils2
int			ft_atoi(const char *nptr);
char		*ft_itoa(int nb);
int			ft_strcmp(char *s1, char *s2);

//utils3	
void		start_program(pthread_mutex_t *program);
void		print_status(t_philo *philo, long long time, char *act);
void		send_obituary(t_data *data, int id);
void		check_if_all_full(t_data *data);
bool		take_forks(t_philo *philo);
void		release_forks(t_philo *philo);
void		join_threads(t_data *data);

//events
bool		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

#endif