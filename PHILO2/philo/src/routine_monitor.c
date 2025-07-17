/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:45:06 by engiusep          #+#    #+#             */
/*   Updated: 2025/07/17 15:19:29 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_done(t_data *data)
{
	pthread_mutex_lock(&data->var_mutex);
	if (data->done == data->nb_philo)
	{
		data->all_is_done = 1;
		pthread_mutex_unlock(&data->var_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->var_mutex);
	return (0);
}

void	check_done(t_data *data, int i)
{
	pthread_mutex_lock(&data->var_mutex);
	if (data->nb_reach_meal != -1)
	{
		if (data->nb_reach_meal == data->philos[i].meals_count)
			data->done++;
	}
	pthread_mutex_unlock(&data->var_mutex);
}

void	check_die(t_data *data, long current_time, int i)
{
	data->someone_die = 1;
	pthread_mutex_unlock(&data->var_mutex);
	pthread_mutex_lock(&data->print_mutex);
	printf("%ld %d died\n", current_time - data->start_time,
		data->philos[i].id);
	pthread_mutex_unlock(&data->print_mutex);
}

int	check_philo(t_data *data, int i, long current_time)
{
	while (i < data->nb_philo)
	{
		check_done(data, i);
		current_time = get_time_ms();
		pthread_mutex_lock(&data->var_mutex);
		if ((current_time
				- data->philos[i].last_meal_time) >= data->time_to_die)
			return (check_die(data, current_time, i), -1);
		pthread_mutex_unlock(&data->var_mutex);
		pthread_mutex_lock(&data->print_mutex);
		if (is_done(data) == 1)
		{
			pthread_mutex_unlock(&data->print_mutex);
			return (-1);
		}
		pthread_mutex_unlock(&data->print_mutex);
		i++;
	}
	return (0);
}

void	*routine_monitor(void *arg)
{
	t_data	*data;
	int		i;
	long	current_time;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		current_time = get_time_ms();
		if (check_philo(data, i, current_time) == -1)
			return (NULL);
	}
	return (NULL);
}
