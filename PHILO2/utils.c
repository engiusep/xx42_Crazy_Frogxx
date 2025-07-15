/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:10:12 by engiusep          #+#    #+#             */
/*   Updated: 2025/07/15 13:10:13 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



long get_time_ms(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((long)(tv.tv_sec) * 1000L + (long)(tv.tv_usec) / 1000L);
}

void	print_mutex(t_philo *philo, int choice)
{
	if(choice == 1)
	{
		pthread_mutex_lock(philo->right_fork);
    	printf("%ld philo[%d] as taken a fork\n",get_time_ms() - philo->data->start_time,philo->id);
    	pthread_mutex_lock(philo->left_fork);
   		printf("%ld philo[%d] as taken a fork\n",get_time_ms() - philo->data->start_time,philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
        printf("%ld philo[%d] as taken a fork\n",get_time_ms() - philo->data->start_time,philo->id);
        pthread_mutex_lock(philo->right_fork);
        printf("%ld philo[%d] as taken a fork\n",get_time_ms() - philo->data->start_time,philo->id);
	}
	return ;
}

