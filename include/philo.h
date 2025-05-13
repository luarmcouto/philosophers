/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarodri <luarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:37:56 by luarodri          #+#    #+#             */
/*   Updated: 2025/05/13 09:30:47 by luarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// # include "colors.h"
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include "terminal_palette.h"

# define MAX_PHILOS 200

typedef struct s_philos
{
	int				id;
	int				eaten;
	int				*dead;
	size_t			num_philos;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*meal_mutex;
	struct s_table	*table;
}				t_philos;

typedef struct s_table
{
	int				dead_flag;
	int				num_of_meals;
	unsigned long	time;
	pthread_t		table;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*eaten_mutex;
	pthread_mutex_t	*forks;
	t_philos		*philos;
}				t_table;

/* validation_utils.c */
int		validate_arguments(int ac, char **av);
size_t	ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_is_not_numeric(char *str);

/* time_utils.c */
int		sleep_for_ms(size_t milliseconds);
size_t	get_current_time(void);

/* dinner_manager.c */
void	start_dinner_simulation(t_table *table);
void	cleanup_simulation(t_table *table, t_philos *philos, char **av);

/* initialization.c */
void	initialize_philosopher_data(t_philos *philosopher, char **av);
void	initialize_all_philosophers(t_table *table,
			t_philos *philosophers, char **av);
void	initialize_table(t_philos *philosophers, t_table *table, char **av);

/* philosopher_actions.c */
void	*philosopher_lifecycle(void *arg);
void	eat_action(t_philos *philosopher);
void	sleep_action(t_philos *philosopher);
void	think_action(t_philos *philosopher);
void	lock_forks(t_philos *philo, pthread_mutex_t *own,
			pthread_mutex_t *next);
void	unlock_forks(pthread_mutex_t *own, pthread_mutex_t *next);

/* philosopher_utils.c */
int		handle_single_philosopher(t_philos *philosopher);
int		ft_strcmp(char *s1, char *s2);
void	print_philosophers_debug(t_philos *philosopher);
void	log_philosopher_action(t_philos *philo, char *message);

/* philosopher_monitor.c */
int		check_philosopher_state(t_philos *philosopher);
int		is_philosopher_starved(t_philos *philosopher);
int		check_for_dead_philosophers(t_philos *philosophers);
int		check_all_philosophers_ate(t_philos *philosophers);
void	*monitor_philosophers(void *arg);

#endif
