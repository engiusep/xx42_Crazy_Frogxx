/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:08:47 by engiusep          #+#    #+#             */
/*   Updated: 2025/07/17 14:41:38 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_mutex(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->var_mutex);
	if (philo->data->someone_die == 1)
	{
		unlocked(philo);
		pthread_mutex_unlock(&philo->data->var_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->var_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d %s\n", get_time_ms() - philo->data->start_time, philo->id,
		str);
	pthread_mutex_unlock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->data->var_mutex);
	if (philo->data->all_is_done == 1)
	{
		pthread_mutex_unlock(&philo->data->var_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->var_mutex);
	return (0);
}

void	mutex_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->var_mutex);
	philo->last_meal_time = get_time_ms();
	philo->meals_count++;
	pthread_mutex_unlock(&philo->data->var_mutex);
}
void	*routine_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (print_mutex(philo, "is thinking") == 1)
			return (unlocked(philo), NULL);
		if (take_fork(philo) == 1)
			return (unlocked(philo), NULL);
		if (print_mutex(philo, "is eating") == 1)
			return (unlocked(philo), NULL);
		usleep(philo->data->time_to_eat * 1000);
		mutex_meal(philo);
		unlocked(philo);
		if (print_mutex(philo, "is sleeping") == 1)
			return (NULL);
		usleep(philo->time_to_sleep * 1000);
	}
	return (NULL);
}
