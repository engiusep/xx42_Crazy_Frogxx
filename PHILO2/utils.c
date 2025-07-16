/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:10:12 by engiusep          #+#    #+#             */
/*   Updated: 2025/07/16 12:48:43 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)(tv.tv_sec) * 1000L + (long)(tv.tv_usec) / 1000L);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_mutex(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	print_mutex(philo, "has taken a fork");
}
