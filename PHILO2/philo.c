/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:10:02 by engiusep          #+#    #+#             */
/*   Updated: 2025/07/16 15:07:08 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_data *data, t_philo **philos)
{
	int	i;

	i = 0;
	*philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!(*philos))
		return (-1);
	data->philos = *philos;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (-1);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		(*philos)[i].id = i + 1;
		(*philos)[i].meals_count = 0;
		(*philos)[i].last_meal_time = get_time_ms();
		(*philos)[i].left_fork = &data->forks[i];
		(*philos)[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
		(*philos)[i].data = data;
		i++;
	}
	return (0);
}

int	check_data(t_data *data)
{
	if (data->nb_philo < 0 || data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0)
	{
		printf("Error: put a positive number\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("wrong input\n");
		exit(EXIT_FAILURE);
	}
	data->nb_philo = ft_atoi(argv[1]);
	data->done = 0;
	data->someone_die = 0;
	data->all_is_done = 0;
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_reach_meal = ft_atoi(argv[5]);
	else
		data->nb_reach_meal = -1;
	data->start_time = 0;
	check_data(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;
	int		i;

	i = 0;
	init_data(&data, argc, argv);
	if (init_philo(&data, &philos) == -1)
		return (-1);
	pthread_mutex_init(&data.print_mutex, NULL);
	pthread_mutex_init(&data.var_mutex_meal, NULL);
	data.start_time = get_time_ms();
	while (i < data.nb_philo)
	{
		pthread_create(&philos[i].thread, NULL, &routine_philo, &philos[i]);
		i++;
	}
	pthread_create(&data.thread_monitor, NULL, &routine_monitor, &data);
	i = 0;
	while (i < data.nb_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(data.thread_monitor, NULL);
	free(philos);
	free(data.forks);
}
