/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarodri <luarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:23:58 by luamonteiro       #+#    #+#             */
/*   Updated: 2025/05/04 19:43:02 by luarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_single_philosopher(t_philos *philo)
{
	sleep_for_ms(1);
	if (philo->num_philos == 1)
	{
		log_philosopher_action(philo, "has taken a fork");
		sleep_for_ms(philo->time_die);
		pthread_mutex_lock(philo->table->dead_mutex);
		*philo->dead = 1;
		pthread_mutex_unlock(philo->table->dead_mutex);
		return (0);
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	log_philosopher_action(t_philos *philo, char *message)
{
	size_t	current_time;
	int		should_print;

	current_time = get_current_time() - philo->table->time;
	should_print = 1;
	pthread_mutex_lock(&philo->table->mutex);
	pthread_mutex_lock(philo->table->dead_mutex);
	if (*philo->dead && ft_strcmp(message, "died") != 0)
		should_print = 0;
	if (should_print)
	{
		printf(WHITE"%4zi "DEFAULT, current_time);
		if (ft_strcmp(message, "has taken a fork") == 0)
			printf(BOLD"%i "GREEN"%s %8s\n"DEFAULT, philo->id, message, "🍽️");
		else if (ft_strcmp(message, "is eating") == 0)
			printf(BOLD"%i "BLUE"%12s %9s\n"DEFAULT, philo->id, message, "🥘");
		else if (ft_strcmp(message, "is sleeping") == 0)
			printf(BOLD"%i "RED"%13s %8s\n"DEFAULT, philo->id, message, "💤");
		else if (ft_strcmp(message, "is thinking") == 0)
			printf(BOLD"%i "CYAN"%13s %8s\n"DEFAULT, philo->id, message, "🤔");
		else if (ft_strcmp(message, "died") == 0)
			printf(RED"%i %9s %14s\n"DEFAULT, philo->id, message, "☠️");
	}
	pthread_mutex_unlock(philo->table->dead_mutex);
	pthread_mutex_unlock(&philo->table->mutex);
}
