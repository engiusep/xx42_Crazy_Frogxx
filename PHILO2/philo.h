/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:55:37 by engiusep          #+#    #+#             */
/*   Updated: 2025/03/31 12:22:43 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#define TIME get_time_ms() - philo->start_time

typedef struct s_philo
{
    int id;
    int meals_count;
    long last_meal_time;
    pthread_t thread;

    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    struct s_data *data;
}   t_philo;

typedef struct s_data
{
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_reach_meal;
    long start_time;

    int someone_died;

    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;

    t_philo *philos;
}   t_data;


int ft_atoi(const char *str);
long	get_time_ms(void);
void *routine_philo(void *arg);

#endif
