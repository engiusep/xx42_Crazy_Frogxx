/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:27:40 by engiusep          #+#    #+#             */
/*   Updated: 2025/03/25 15:11:20 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long get_time_ms()
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	lock_and_print(char *str, long time, int id, pthread_mutex_t *printex)
{
	pthread_mutex_lock(printex);
	printf("%ld %d %s\n",time, id, str);
	pthread_mutex_unlock(printex);
}