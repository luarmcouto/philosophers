/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarodri <luarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 00:02:26 by luarodri          #+#    #+#             */
/*   Updated: 2025/05/04 20:22:55 by luarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_lifecycle(void *arg)
{
	t_philos	*philosopher;

	philosopher = (t_philos *)arg;
	if (philosopher->id % 2 == 0)
		sleep_for_ms(1);
	while (!check_philosopher_state(philosopher))
	{
		eat_action(philosopher);
		sleep_action(philosopher);
		think_action(philosopher);
	}
	return (arg);
}

void	eat_action(t_philos *philosopher)
{
	pthread_mutex_t	*next_fork;
	pthread_mutex_t	*own_fork;

	own_fork = &philosopher->table->forks
	[(philosopher->id - 1) % philosopher->num_philos];
	next_fork = &philosopher->table->forks
	[(philosopher->id) % philosopher->num_philos];
	if (philosopher->id % 2 == 0)
	{
		next_fork = own_fork;
		own_fork = &philosopher->table->forks
		[(philosopher->id) % philosopher->num_philos];
	}
	lock_forks(philosopher, own_fork, next_fork);
	log_philosopher_action(philosopher, "is eating");
	pthread_mutex_lock(philosopher->meal_mutex);
	philosopher->last_meal = get_current_time();
	pthread_mutex_lock(philosopher->table->eaten_mutex);
	philosopher->eaten++;
	pthread_mutex_unlock(philosopher->table->eaten_mutex);
	pthread_mutex_unlock(philosopher->meal_mutex);
	sleep_for_ms(philosopher->time_eat);
	unlock_forks(own_fork, next_fork);
}

void	sleep_action(t_philos *philosopher)
{
	log_philosopher_action(philosopher, "is sleeping");
	sleep_for_ms(philosopher->time_sleep);
}

void	think_action(t_philos *philosopher)
{
	log_philosopher_action(philosopher, "is thinking");
}
