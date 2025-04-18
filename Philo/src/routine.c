/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:41:44 by engiusep          #+#    #+#             */
/*   Updated: 2025/03/31 16:03:52 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0) {
        pthread_mutex_lock(philo->left_fork);
        lock_and_print("has taken a left", TIME , philo->id , philo->printex);
        pthread_mutex_lock(philo->right_fork);
        lock_and_print("has taken a right", TIME , philo->id , philo->printex); 
    } else {
        pthread_mutex_lock(philo->right_fork);
        lock_and_print("has taken a right", TIME , philo->id , philo->printex);
        pthread_mutex_lock(philo->left_fork);
        lock_and_print("has taken a left", TIME , philo->id , philo->printex);
    }
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	routine_eat(t_philo *philo)
{
	take_forks(philo);
	lock_and_print("is eating", TIME, philo->id, philo->printex);
	usleep(philo->time_eat * 1000);
	drop_forks(philo);
	// pthread_mutex_lock(philo->eatex);
	// philo->nb_meal += 1;
	// philo->last_meal = get_time_ms();
	// pthread_mutex_unlock(philo->eatex);
}

void	routine_sleep(t_philo *philo)
{
	lock_and_print("is sleeping",TIME ,philo->id, philo->printex);
	usleep(philo->time_sleep * 1000);
}

void	routine_thinks(t_philo *philo)
{
	lock_and_print("is thinking",TIME ,philo->id, philo->printex);
}

