/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarodri <luarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:14:25 by luarodri          #+#    #+#             */
/*   Updated: 2025/05/13 09:30:48 by luarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_dinner_simulation(t_table *table)
{
	size_t	i;

	i = 0;
	table->time = get_current_time();
	if (pthread_create(&table->table, NULL,
			monitor_philosophers, table->philos) != 0)
		write(2, "Failed to create thread\n", 22);
	while (i < table->philos->num_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL,
				philosopher_lifecycle, &table->philos[i]) != 0)
			write(2, "Failed to create thread\n", 22);
		i++;
	}
	i = 0;
	while (i < table->philos->num_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	pthread_join(table->table, NULL);
}

void	cleanup_simulation(t_table *table, t_philos *philos, char **av)
{
	size_t	i;

	i = 0;
	(void) av;
	pthread_mutex_destroy(&table->mutex);
	pthread_mutex_destroy(table->dead_mutex);
	free(table->dead_mutex);
	pthread_mutex_destroy(table->eaten_mutex);
	free(table->eaten_mutex);
	while (i < table->philos->num_philos)
	{
		pthread_mutex_destroy(philos[i].meal_mutex);
		free(philos[i].meal_mutex);
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
}
