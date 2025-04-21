/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarodri <luarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:37:56 by luarodri          #+#    #+#             */
/*   Updated: 2025/04/21 21:37:27 by luarodri         ###   ########.fr       */
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
	int				sleep;
	int				eaten;
	int				*dead;
	size_t			num_philos;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*meal_mutex;
	pthread_mutex_t	*eaten_mutex;
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


/* initialization.c */
void	initialize_table(t_philos *philosophers, t_table *table, char **av);
void	initialize_all_philosophers(t_table *table, t_philos *philosophers, char **av);
void	initialize_philosopher_data(t_philos *philosopher, char **av);

/* time_utils.c */
int		sleep_for_ms(size_t milliseconds);
size_t	get_current_time(void);

#endif
