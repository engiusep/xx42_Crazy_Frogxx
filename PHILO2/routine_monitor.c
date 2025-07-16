/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:45:06 by engiusep          #+#    #+#             */
/*   Updated: 2025/07/16 12:56:01 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_monitor(void *arg)
{
	t_data	*data;
	int		i;
	long	current_time;

	data = (t_data *)arg;
	while (1)
	{
		usleep(1000);
		i = 0;
		current_time = get_time_ms();
		pthread_mutex_lock(&data->var_mutex_meal);
		if (data->someone_died)
		{
			pthread_mutex_unlock(&data->print_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&data->var_mutex_meal);
		while (i < data->nb_philo)
		{
			current_time = get_time_ms();
			pthread_mutex_lock(&data->var_mutex_meal);
			if (data->someone_died)
			{
				pthread_mutex_unlock(&data->var_mutex_meal);
				return (NULL);
			}
			if ((current_time
					- data->philos[i].last_meal_time) >= data->time_to_die)
			{
				data->someone_died = 1;
				printf("%ld %d died\n", current_time - data->start_time,
					data->philos[i].id);
				pthread_mutex_unlock(&data->var_mutex_meal);
				return (NULL);
			}
			pthread_mutex_unlock(&data->print_mutex);
			i++;
		}
	}
	return (NULL);
}
// 	if (monitor->data->nb_reach_meal != -1)
// 	{
// 		int philosophers_done = 0;
// 		i = 0;
// 		while (i < monitor->data->nb_philo)
// 		{
// 			if (monitor->data->philos[i].meals_count >= monitor->data->nb_reach_meal)
// 				philosophers_done++;
// 			i++;
// 		}
// 		if (philosophers_done == monitor->data->nb_philo)
// 		{
// 			monitor->data->someone_died = 1;
// 			return (NULL);
// 		}
// 	}
// }
// return (NULL);
