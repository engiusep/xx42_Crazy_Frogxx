/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:34:32 by engiusep          #+#    #+#             */
/*   Updated: 2025/03/31 13:11:09 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_monitor(void *arg)
{
	t_info *info;
	
	info = (t_info *)arg;
	while(1)
	{
		// if(all_philo_dead(info) == 1)// || everyone_eat() == 1)
		// {
		// 	break;
		// }
		usleep(1);
	}
	return (NULL);
}

void	create_monitor(t_info info)
{
	pthread_t monitor;	
	pthread_create(&monitor, NULL, &routine_monitor, (void *)&info);
}


//pointeur sur time