/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:59:01 by engiusep          #+#    #+#             */
/*   Updated: 2025/03/31 15:30:39 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *)arg;
	
	if(philo->id % 2 == 0)
		usleep(1);
	while(1)
	{
		routine_eat(philo);
		routine_sleep(philo);
		routine_thinks(philo);
	}
	return NULL;
}
void	init_data_philo(t_info info, t_mutex mutex, t_philo *philo,int index)
{
	philo->id = index + 1;
	philo->time_die = info.time_die;
	philo->time_eat = info.time_eat;
	philo->time_sleep = info.time_sleep;
	philo->start_time = info.start_time;
	philo->last_meal = get_time_ms();
	philo->printex = &mutex.printex;
	philo->eatex = &mutex.eatex;
	philo->deadex = &mutex.deadex;
	philo->meal_to_reach = info.meal_to_reach;
	philo->nb_meal = 0;
	philo->is_dead = &info.is_dead;
	philo->left_fork = &mutex.forks[index];
	philo->right_fork = &mutex.forks[(index + 1) % info.nb_philo];
}


void create_philo(t_info info, t_mutex mutex)
{
	int i;

	i = 0;
	
	info.start_time = get_time_ms();
	while(i < info.nb_philo)
	{
		init_data_philo(info, mutex, &info.philos_list[i], i);
		pthread_create(&info.philos_list[i].thread, NULL, &philo_routine, (void *)&info.philos_list[i]);
		i++;
	}
}

void	wait_thread(t_info info)
{
	
	int i;
	
	i = 0;
	while(i < info.nb_philo)
	{
		pthread_join(info.philos_list[i].thread,NULL);
		i++;
	}
}