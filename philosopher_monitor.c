/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_monitor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarodri <luarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:48:46 by luarodri          #+#    #+#             */
/*   Updated: 2025/04/22 00:07:18 by luarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philosopher_state(t_philos *philosopher)
{
	pthread_mutex_lock(philosopher->table->dead_mutex);
	if (*philosopher->dead)
		return (pthread_mutex_unlock(philosopher->table->dead_mutex), 1);
	pthread_mutex_unlock(philosopher->table->dead_mutex);
	return (0);
}

int	is_philosopher_starved(t_philos *philosopher)
{
	pthread_mutex_lock(philosopher->meal_mutex);
	if (get_current_time() - philosopher->last_meal > philosopher->time_die)
		return (pthread_mutex_unlock(philosopher->meal_mutex), 1);
	pthread_mutex_unlock(philosopher->meal_mutex);
	return (0);
}

int	check_for_dead_philosophers(t_philos *philosophers)
{
	size_t	i;

	i = 0;
	while (i < philosophers[0].num_philos)
	{
		if (is_philosopher_starved(&philosophers[i]))
		{
			pthread_mutex_lock(philosophers->table->dead_mutex);
			if (!*philosophers->dead)
			{
				pthread_mutex_unlock(philosophers->table->dead_mutex);
				log_philosopher_action(&philosophers[i], "died");
				pthread_mutex_lock(philosophers->table->dead_mutex);
				*philosophers->dead = 1;
				pthread_mutex_unlock(philosophers->table->dead_mutex);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_all_philosophers_ate(t_philos *philosophers)
{
	size_t	i;
	int		total_satisfied;

	i = 0;
	total_satisfied = 0;
	while (i < philosophers[0].num_philos)
	{
		pthread_mutex_lock(philosophers->table->eaten_mutex);
		if (philosophers[i].eaten >= philosophers->table->num_of_meals
			&& philosophers->table->num_of_meals != -1)
			total_satisfied++;
		pthread_mutex_unlock(philosophers->table->eaten_mutex);
		i++;
	}
	if (total_satisfied == (int)philosophers[0].num_philos)
	{
		pthread_mutex_lock(philosophers->table->dead_mutex);
		*philosophers->dead = 1;
		pthread_mutex_unlock(philosophers->table->dead_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_philosophers(void *arg)
{
	t_philos	*philosophers;

	philosophers = (t_philos *)arg;
	while (1)
		if (check_for_dead_philosophers(philosophers) || 
            check_all_philosophers_ate(philosophers))
			break ;
	return (arg);
}
