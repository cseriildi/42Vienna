/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:20:25 by icseri            #+#    #+#             */
/*   Updated: 2024/08/14 08:52:54 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>
# include <pthread.h>
# include <string.h>

typedef enum s_err
{
	MALLOC_FAIL = 2,
	MISUSE,
	INCORRECT_INPUT,
	FORK_FAIL,
	SEM_FAIL
}	t_err;

struct s_data;

typedef struct s_sems
{
	sem_t	*forks;
	sem_t	*full;
	sem_t	*dead;
	sem_t	*print;
}	t_sems;

typedef struct s_philo
{
	int				id;
	int				initial_thinking_time;
	int				pid;
	struct s_data	*data;
}	t_philo;


typedef struct s_data
{
	int			count;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_think;
	int			min_eat_count;
	long long	start_time;
	t_philo		*philos;
	t_sems		sems;
	pthread_t	dead_monitor;
	pthread_t	full_monitor;
}	t_data;

typedef struct s_inprocess_data
{
	int			id;
	int			initial_thinking_time;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_think;
	int			min_eat_count;
	int 		philo_count;
	long long 	start_time;
	long long	last_eating_time;
	int			eat_count;
	t_sems		sems;
}	t_inprocess_data;

//init
void				init_data(t_data *data, int argc, char **argv);
void				init_philos(t_data *data);
void				init_processes(t_data *data);
void				init_semaphores(t_data *data);
void				init_threads(t_data *data);

//time
long long			get_time(void);
long long			get_elapsed_time(long long start_time);
void				ft_usleep(long long time, t_inprocess_data philo);

//simulation
void				simulation(t_philo *philo);
t_inprocess_data	get_philo_data(t_philo *philo, t_data *data);
t_inprocess_data	open_semaphores(t_inprocess_data philo);

//events
t_inprocess_data	eating(t_inprocess_data philo);
void				sleeping(t_inprocess_data philo);
void				thinking(t_inprocess_data philo);

//monitor
void				*dead_monitor(void *arg);
void				*full_monitor(void *arg);

//utils
void				check_input(int argc, char **argv);
int					wait_processes(t_data *data);
void				safe_print(t_inprocess_data philo, char *str);
void				safe_close_sem(sem_t *sem, char *name);

//libft
int					ft_atoi(const char *nptr);
char				*ft_itoa(int nb);
int					ft_strcmp(char *s1, char *s2);

//cleanup
void				ft_putendl_fd(char *s, int fd);
void				print_error(int code);
void				safe_exit(t_data *data, int exit_code);
void				safe_process_exit(t_inprocess_data data, int exit_code);
void				kill_processes(t_data *data);

#endif