/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:20:25 by icseri            #+#    #+#             */
/*   Updated: 2024/09/13 15:39:27 by icseri           ###   ########.fr       */
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
# include <semaphore.h>
# include <fcntl.h>
# include <pthread.h>
# include <string.h>

typedef enum s_err
{
	MALLOC_FAIL = 2,
	MISUSE,
	INCORRECT_INPUT,
	THREAD_CREATE_FAIL,
	FORK_FAIL,
	SEM_FAIL
}	t_err;

struct	s_data;

typedef struct s_sems
{
	sem_t	*forks;
	sem_t	*take2forks;
	sem_t	*full;
	sem_t	*dead;
	sem_t	*print;
	sem_t	*check_status;
	sem_t	*program;
}	t_sems;

typedef struct s_philo
{
	int				id;
	int				initial_thinking_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				min_eat_count;
	int				count;
	long long		start_time;
	long long		last_eating_time;
	int				eat_count;
	t_sems			sems;
	pthread_t		thread;
	pthread_t		monitor;
	bool			running;
}	t_philo;

typedef struct s_data
{
	int				argc;
	char			**argv;
	int				count;
	t_sems			sems;
	pthread_t		dead_monitor;
	pthread_t		full_monitor;
	pid_t			*pids;
	long long		start_time;
}	t_data;

//init
void		init_data(t_data *data, int argc, char **argv);
void		init_philo(t_philo *philo, int i, t_data *data);
void		init_processes(t_data *data);
void		init_semaphores(t_data *data);
void		init_threads(t_data *data);

//time
long long	get_time(void);
long long	get_elapsed_time(long long start_time);
bool		ft_usleep(long long time, t_philo *philo);

//simulation
void		simulation(t_philo *philo);
void		*routine(void *arg);
void		*dead_monitor(void *arg);
void		*full_monitor(void *arg);
void		*monitor(void *arg);

//events
bool		eating(t_philo *philo);
bool		sleeping(t_philo *philo);
bool		thinking(t_philo *philo);
bool		take_forks(t_philo *philo);
void		dying(t_philo *philo);

//utils
void		check_input(int argc, char **argv);
int			wait_processes(t_data *data);
void		safe_print(t_philo *philo, char *str);
sem_t		*safe_open_sem( char *name, int value);
void		safe_close_sem(sem_t *sem, char *name);
bool		is_running(t_philo *philo);

//libft
int			ft_atoi(const char *nptr);
char		*ft_itoa(int nb);
int			ft_strcmp(char *s1, char *s2);

//libft2
void		ft_putendl_fd(char *s, int fd);
void		*ft_calloc(size_t nmemb, size_t size);

//cleanup
void		print_error(int code);
void		safe_exit(t_data *data, int exit_code);
void		safe_process_exit(t_philo *philo, int exit_code);
void		death_alert(t_sems sems, int count);

#endif