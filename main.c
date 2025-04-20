/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarodri <luarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:41:09 by luarodri          #+#    #+#             */
/*   Updated: 2025/04/20 21:54:33 by luarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	//t_table		table;
	//t_philos	philosophers[MAX_PHILOS];

	if (validate_arguments(ac, av))
		return (1);
	//initialize_table();//TODO
	//initialize_all_philosophers();//TODO
	//start_dinner_simulation();//TODO
	//cleanup_simulation();//TODO
	return (0);
}