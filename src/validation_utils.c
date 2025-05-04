/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarodri <luarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:11:59 by luarodri          #+#    #+#             */
/*   Updated: 2025/05/04 20:27:15 by luarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_arguments(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf(BOLD_RED"Oops! 🤔 Wrong arguments!\n"
				BOLD_GREEN"Try: ./bin/philo 5 500 600 800\n"DEFAULT));
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > MAX_PHILOS)
		return (printf(BOLD_RED"Invalid number of philosophers! 🧠\n"
				"Neither zero nor an army, please! 🤯\n"DEFAULT));
	if (ft_atoi(av[2]) <= 0 || ft_is_not_numeric(av[2]))
		return (printf(BOLD_RED"Invalid time_to_die! ☠️\n"
				"Philos need a realistic time to die..."
				" morbid, right? 😱\n"DEFAULT));
	if (ft_atoi(av[3]) <= 0 || ft_is_not_numeric(av[3]))
		return (printf(BOLD_RED"Invalid time_to_eat! 🍔\n"
				"Even philosophers need to chew, you know? 🤓\n"DEFAULT));
	if (ft_atoi(av[4]) <= 0 || ft_is_not_numeric(av[4]))
		return (printf(BOLD_RED"Invalid time_to_sleep! 💤\n"
				"Philosophers need their beauty sleep too! 😴\n"DEFAULT));
	if (ac == 6 && (ft_atoi(av[5]) <= 0 || ft_is_not_numeric(av[5])))
		return (printf(BOLD_RED"Invalid eat_times! 🍝\n"
				"How many times should they eat? Not THAT number! 🍴\n"DEFAULT));
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	length;

	length = 0;
	if (!str)
		return (-1);
	while (str[length])
		length++;
	return (length);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	if (!str)
		return (-1);
	while (str[i] >= '\t' && str[i] <= '\r' && str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * sign);
}

int	ft_is_not_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i++] > '9')
			return (1);
	}
	return (0);
}
