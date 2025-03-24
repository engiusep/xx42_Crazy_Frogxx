#include "philo.h"


void    create_forks(t_info_table *info)
{
    int i;

    i = 0;
    while(i < info->nb_philo)
    {
        pthread_mutex_init(&info->forks[i],NULL);
            i++;
    }
}