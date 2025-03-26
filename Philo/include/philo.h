/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:55:37 by engiusep          #+#    #+#             */
/*   Updated: 2025/03/26 15:50:59 by engiusep         ###   ########.fr       */
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

#define TIME get_time_ms() - philo->start_time

typedef	struct s_mutex
{
	pthread_mutex_t *forks;
	pthread_mutex_t printex;
	// pthread_mutex_t *eatex;
	
}t_mutex;

typedef struct s_philo
{
	pthread_t thread;
	int id;
	long time_die;
	long time_eat;
	long time_sleep;
	long start_time;
	long last_meal;
	
	int meal_to_reach;
	int nb_meal;
	
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *printex;
	
}t_philo;

typedef struct s_info
{
	long time_die;
	long time_eat;
	long time_sleep;
	long start_time;
	int meal_to_reach;
	int nb_philo;
	t_philo *philos_list;
	
}t_info;

// create
void create_forks(t_info *info, t_mutex *mutex);
void create_mutex_utils(t_info info, t_mutex *mutex);
t_philo *create_philo(t_philo *philos, t_info info, t_mutex mutex);

// destroy
void destroy_forks(t_mutex *mutex, int nb);
void	destroy_mutex_utils(t_mutex *mutex);

// time 
long get_time_ms();
//utils
void	lock_and_print(char *str, long time, int id, pthread_mutex_t *printex);
void	wait_thread(t_philo *philos_list, t_info info);
//routine 
void	routine_eat(t_philo *philo);
void	routine_sleep(t_philo *philo);
void	routine_thinks(t_philo *philo);
#endif
