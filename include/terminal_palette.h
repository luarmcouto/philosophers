/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_palette.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarodri <luarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:16:46 by luarodri          #+#    #+#             */
/*   Updated: 2025/04/20 20:43:21 by luarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_PALETTE_H
# define TERMINAL_PALETTE_H

/* Reset all formatting */
# define RESET       "\033[0m"

/* Basic colors */
# define DEFAULT     "\033[0;39m"
# define BLACK       "\033[0;30m"
# define RED         "\033[0;31m"
# define GREEN       "\033[0;32m"
# define YELLOW      "\033[0;33m"
# define BLUE        "\033[0;34m"
# define MAGENTA     "\033[0;35m"
# define CYAN        "\033[0;36m"
# define WHITE       "\033[0;37m"

/* High intensity colors */
# define GRAY        "\033[0;90m"
# define BRIGHT_RED      "\033[0;91m"
# define BRIGHT_GREEN    "\033[0;92m"
# define BRIGHT_YELLOW   "\033[0;93m"
# define BRIGHT_BLUE     "\033[0;94m"
# define BRIGHT_MAGENTA  "\033[0;95m"
# define BRIGHT_CYAN     "\033[0;96m"
# define BRIGHT_WHITE    "\033[0;97m"

/* Text styles */
# define BOLD        "\033[1m"
# define DIM         "\033[2m"
# define ITALIC      "\033[3m"
# define UNDERLINE   "\033[4m"
# define BLINK       "\033[5m"
# define REVERSE     "\033[7m"
# define HIDDEN      "\033[8m"

/* Bold colored text */
# define BOLD_BLACK      "\033[1;30m"
# define BOLD_RED        "\033[1;31m"
# define BOLD_GREEN      "\033[1;32m"
# define BOLD_YELLOW     "\033[1;33m"
# define BOLD_BLUE       "\033[1;34m"
# define BOLD_MAGENTA    "\033[1;35m"
# define BOLD_CYAN       "\033[1;36m"
# define BOLD_WHITE      "\033[1;37m"

/* Additional colors */
# define ORANGE          "\033[0;38;5;208m"
# define PURPLE          "\033[0;38;5;129m"
# define PINK            "\033[0;38;5;213m"
# define LIGHT_BLUE      "\033[0;38;5;39m"
# define LIME            "\033[0;38;5;118m"
# define TEAL            "\033[0;38;5;30m"
# define LAVENDER        "\033[0;38;5;183m"
# define BROWN           "\033[0;38;5;130m"
# define GOLD            "\033[0;38;5;220m"
# define SILVER          "\033[0;38;5;246m"

/* Philosophers project specific colors */
# define PHILO_THINKING  "\033[0;38;5;39m"   /* Light blue */
# define PHILO_EATING    "\033[0;38;5;118m"  /* Lime green */
# define PHILO_SLEEPING  "\033[0;38;5;183m"  /* Lavender */
# define PHILO_FORK      "\033[0;38;5;220m"  /* Gold */
# define PHILO_DIED      "\033[0;91m"        /* Bright red */
# define PHILO_ID        "\033[0;38;5;208m"  /* Orange */
# define PHILO_TIME      "\033[0;90m"        /* Gray */

#endif