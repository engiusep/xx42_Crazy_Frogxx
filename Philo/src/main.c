/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:14:25 by engiusep          #+#    #+#             */
/*   Updated: 2025/03/26 15:52:35 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int check_arg(t_info *info ,int argc, char **argv)
{

	if(argc != 5 && argc != 6)
	{
		printf("wrong input\n");
		exit(EXIT_FAILURE);
	}

	//faire atol warning et negatif value  !!!!! 
	//faire atol warning et negatif value  !!!!! 
	//faire atol warning et negatif value  !!!!! 
	//faire atol warning et negatif value  !!!!! 
	//faire atol warning et negatif value  !!!!! 
	//faire atol warning et negatif value  !!!!! 
	info->nb_philo = atoi(argv[1]);
	info->time_die = atoi(argv[2]);
	info->time_eat = atoi(argv[3]);
	info->time_sleep = atoi(argv[4]);
	if(argc == 6)
		info->meal_to_reach = atoi(argv[5]);
	else
		info->meal_to_reach = -1;
	return (0);
}



int main (int argc, char **argv)
{
	t_info info;
	t_mutex mutex;
	
	t_philo *philos_list;

	philos_list = NULL;
	//pthread_t monitor;
	//check argument
	
	check_arg(&info, argc, argv);
	// init mutex forks
	create_forks(&info, &mutex);
	
	create_mutex_utils(info, &mutex);

	//creat monitor
	
	
	// init philo
	philos_list = create_philo(philos_list, info, mutex);
	// init info 

	//creat philo

	// wait thread
	wait_thread(philos_list,info);
	//destroy thread mutex
	
}