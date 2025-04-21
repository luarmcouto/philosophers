/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarodri <luarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:41:09 by luarodri          #+#    #+#             */
/*   Updated: 2025/04/21 22:28:28 by luarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table		table;
	t_philos	philosophers[MAX_PHILOS];

	if (validate_arguments(ac, av))
		return (1);
	initialize_table(philosophers, &table, av);
	initialize_all_philosophers(&table, philosophers, av);
	start_dinner_simulation(&table);//TODO
	//cleanup_simulation();//TODO
	return (0);
}