/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarodri <luarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:28:28 by luarodri          #+#    #+#             */
/*   Updated: 2025/05/13 09:30:52 by luarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_all_philosophers(t_table *table,
			t_philos *philosophers, char **av)
{
	size_t	i;

	i = 0;
	while (i < (size_t)ft_atoi(av[1]))
	{
		philosophers[i].id = i + 1;
		philosophers[i].table = table;
		initialize_philosopher_data(&philosophers[i], av);
		i++;
	}
}

void	initialize_philosopher_data(t_philos *philosopher, char **av)
{
	philosopher->eaten = 0;
	philosopher->num_philos = ft_atoi(av[1]);
	philosopher->time_die = ft_atoi(av[2]);
	philosopher->time_eat = ft_atoi(av[3]);
	philosopher->time_sleep = ft_atoi(av[4]);
	philosopher->dead = &philosopher->table->dead_flag;
	philosopher->meal_mutex = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philosopher->meal_mutex, NULL);
	philosopher->last_meal = get_current_time();
}

void	initialize_table(t_philos *philosophers, t_table *table, char **av)
{
	size_t	i;

	table->philos = philosophers;
	pthread_mutex_init(&table->mutex, NULL);
	table->dead_mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(table->dead_mutex, NULL);
	table->eaten_mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(table->eaten_mutex, NULL);
	i = 0;
	table->forks = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	while (i < (size_t)ft_atoi(av[1]))
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	table->dead_flag = 0;
	if (av[5])
		table->num_of_meals = ft_atoi(av[5]);
	else
		table->num_of_meals = -1;
}
