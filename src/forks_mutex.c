/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarodri <luarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:20:55 by luarodri          #+#    #+#             */
/*   Updated: 2025/05/04 20:22:51 by luarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_philos *philo, pthread_mutex_t *own, pthread_mutex_t *next)
{
	pthread_mutex_lock(own);
	log_philosopher_action(philo, "has taken a fork");
	pthread_mutex_lock(next);
	log_philosopher_action(philo, "has taken a fork");
}

void	unlock_forks(pthread_mutex_t *own, pthread_mutex_t *next)
{
	pthread_mutex_unlock(own);
	pthread_mutex_unlock(next);
}
