/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:59:42 by engiusep          #+#    #+#             */
/*   Updated: 2025/03/31 13:07:12 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_dead(t_philo philo)
{
	int i;
	
	i = 0;
	//pthread_mutex_lock(philo.deadex);
	printf("time alive : %ld\n",philo.last_meal);
	usleep(100000);
	if(get_time_ms() - philo.last_meal > philo.time_die)
	{
		philo.is_dead = (int *)1;
		return (1);//(pthread_mutex_unlock(philo.deadex), 1);
	}
	//pthread_mutex_unlock(philo.deadex);
	return (0);
}
int all_philo_dead(t_info *info)
{
	int i;
	i = 0;
	if(info->philos_list == NULL)
		return 0;
	while(i < info->nb_philo)
	{
		if(philo_dead(info->philos_list[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int everyone_eat()
{
	
	return (0);
}