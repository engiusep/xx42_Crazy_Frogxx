/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:08:47 by engiusep          #+#    #+#             */
/*   Updated: 2025/07/15 15:48:04 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine_philo(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while(philo->data->someone_died == 0)
    {
        printf("%ld philo[%d] is thinking\n",get_time_ms(),philo->id);
        if(philo->id % 2 == 0)
        {
            pthread_mutex_lock(philo->right_fork);
            pthread_mutex_lock(&philo->data->print_mutex);
            printf("%ld philo[%d] as taken a fork\n",get_time_ms(),philo->id);
            pthread_mutex_unlock(&philo->data->print_mutex);
            pthread_mutex_lock(philo->left_fork);
            pthread_mutex_lock(&philo->data->print_mutex);
            printf("%ld philo[%d] as taken a fork\n",get_time_ms(),philo->id);
            pthread_mutex_unlock(&philo->data->print_mutex);
        }
        else
        {
            pthread_mutex_lock(philo->left_fork);
            pthread_mutex_lock(&philo->data->print_mutex);
            printf("%ld philo[%d] as taken a fork\n",get_time_ms(),philo->id);
            pthread_mutex_unlock(&philo->data->print_mutex);
            pthread_mutex_lock(philo->right_fork);
            pthread_mutex_lock(&philo->data->print_mutex);
            printf("%ld philo[%d] as taken a fork\n",get_time_ms(),philo->id);
            pthread_mutex_unlock(&philo->data->print_mutex);
        }
        pthread_mutex_lock(&philo->data->print_mutex);
        printf("%ld philo[%d] is eating\n",get_time_ms(),philo->id);
        philo->last_meal_time = get_time_ms();
        pthread_mutex_unlock(&philo->data->print_mutex);
        usleep(philo->data->time_to_eat * 1000);
        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_lock(&philo->data->print_mutex);
        printf("%ld philo[%d] is sleeping\n",get_time_ms(),philo->id);
        pthread_mutex_unlock(&philo->data->print_mutex);
        usleep(philo->data->time_to_sleep * 1000);
    }
    return (NULL);
}
