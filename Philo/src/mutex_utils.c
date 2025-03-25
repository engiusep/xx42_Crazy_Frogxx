/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:34:58 by engiusep          #+#    #+#             */
/*   Updated: 2025/03/25 16:17:13 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void create_mutex_utils(t_info info ,t_mutex *mutex)
{
	(void)info;
	//if(
	
	pthread_mutex_init(&mutex->printex, NULL);
	
	// != 0)
	// {
	// 	destroy_forks(mutex,info.nb_philo);
	// 	exit(EXIT_FAILURE);
	// }
}

void	destroy_mutex_utils(t_mutex *mutex)
{
	if(pthread_mutex_destroy(&mutex->printex) != 0)
		exit(EXIT_FAILURE);
}
