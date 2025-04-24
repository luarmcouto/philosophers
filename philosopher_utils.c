/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luamonteiro <luamonteiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:23:58 by luamonteiro       #+#    #+#             */
/*   Updated: 2025/04/24 15:20:01 by luamonteiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_single_philosopher(t_philos *philosopher)
{
	printf("Single philosopher %d handling special case\n", philosopher->id);
	sleep_for_ms(1);
	if (philosopher->num_philos == 1)
	{
		printf("Single philosopher taking one fork and waiting to die\n");
		log_philosopher_action(philosopher, "has taken a fork");
		sleep_for_ms(philosopher->time_die);
		log_philosopher_action(philosopher, "died");
		
		printf("Setting dead flag for single philosopher\n");
		pthread_mutex_lock(philosopher->table->dead_mutex);
		*philosopher->dead = 1;
		pthread_mutex_unlock(philosopher->table->dead_mutex);
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

void	print_philosophers_debug(t_philos *philosopher)
{
	size_t	i;

	i = 0;
	printf("\n--- PHILOSOPHERS DEBUG INFO ---\n");
	while (i < philosopher[0].num_philos)
	{
		printf("philosopher: %zu\n", i + 1);
		printf(YELLOW"philosopher->num_philos:"GREEN"[% 8zi]\n", 
               philosopher[i].num_philos);
		printf(YELLOW"philosopher->time-die:"GREEN"  [% 8zi]\n", 
               philosopher[i].time_die);
		printf(YELLOW"philosopher->time-eat:"GREEN"  [% 8zi]\n", 
               philosopher[i].time_eat);
		printf(YELLOW"philosopher->time-sleep:"GREEN"[% 8zi]\n", 
               philosopher[i].time_sleep);
		printf(YELLOW"philosopher->sleep:"GREEN"[% 8i]\n", philosopher[i].sleep);
		printf(YELLOW"philosopher->eat:"GREEN"[% 8i]\n", philosopher[i].eaten);
		printf(YELLOW"philosopher->dead:"GREEN"[% 8i]\n", *philosopher[i].dead);
		printf("\n"DEFAULT);
		i++;
	}
	printf("--- END DEBUG INFO ---\n\n");
}

void	log_philosopher_action(t_philos *philosopher, char *message)
{
	size_t current_time;
	int should_print = 1;
	
	current_time = get_current_time() - philosopher->table->time;
	
	pthread_mutex_lock(&philosopher->table->mutex);
	pthread_mutex_lock(philosopher->table->dead_mutex);
	
	// Only log if philosopher is not dead (unless this is a death message)
	if (*philosopher->dead && ft_strcmp(message, "died") != 0)
		should_print = 0;
		
	if (should_print)
	{
		printf(WHITE"%4zi "DEFAULT, current_time);
		
		if (ft_strcmp(message, "has taken a fork") == 0)
			printf(BOLD"%i "GREEN"%s %8s\n"DEFAULT, philosopher->id, message, "🍽️");
		else if (ft_strcmp(message, "is eating") == 0)
			printf(BOLD"%i "BLUE"%12s %9s\n"DEFAULT, philosopher->id, message, "🥘");
		else if (ft_strcmp(message, "is sleeping") == 0)
			printf(BOLD"%i "GRAY"%13s %8s\n"DEFAULT, philosopher->id, message, "💤");
		else if (ft_strcmp(message, "is thinking") == 0)
			printf(BOLD"%i "MAGENTA"%13s %8s\n"DEFAULT, philosopher->id, message, "🤔");
		else if (ft_strcmp(message, "died") == 0)
			printf(RED"%i %9s %14s\n"DEFAULT, philosopher->id, message, "☠️");
	}
	
	pthread_mutex_unlock(philosopher->table->dead_mutex);
	pthread_mutex_unlock(&philosopher->table->mutex);
}
