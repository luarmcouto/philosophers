/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarodri <luarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:14:25 by luarodri          #+#    #+#             */
/*   Updated: 2025/04/21 23:35:02 by luarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philosopher_lifecycle(void *arg)
{

    t_philos *philosopher;

    philosopher = (t_philos *)arg;

    if (philosopher->id % 2 == 0)

    sleep_for_ms(1);

    while (!check_philosopher_state(philosopher))
    {
        eat_action();//TODO
        sleep_action();//TODO
        think_action();//TODO
    }
    return (arg);
}

void	start_dinner_simulation(t_table *table)
{
	size_t	i;

	i = 0;
	table->time = get_current_time();
	if (pthread_create(&table->table, NULL, monitor_philosophers, table->philos) != 0)
		write(2, "Failed to create thread\n", 22);
	while (i < table->philos->num_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL,
				philosopher_lifecycle/*TODO*/, &table->philos[i]) != 0)
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
