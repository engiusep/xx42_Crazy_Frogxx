#include "philo.h"


void create_forks(t_info *info,t_mutex *mutex)
{
	int i;

	i = 0;
	mutex->forks = malloc(info->nb_philo * sizeof(pthread_mutex_t));
	if(!mutex->forks)
		exit(EXIT_FAILURE);
	while(i < info->nb_philo)
	{
		if(pthread_mutex_init(&mutex->forks[i],NULL) != 0)
		{
			destroy_forks(mutex, i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void destroy_forks(t_mutex *mutex, int nb)
{
	int i;

	i = 0;

	while(i < nb)
	{
		pthread_mutex_destroy(&mutex->forks[i]);
		i++;
	}
	free(mutex->forks);
}
