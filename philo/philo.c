#include "philo.h"

void    *philo_routine(void *arg)
{
    t_philosophe *philo;

    philo = (t_philosophe *)arg;
    while(1)
    {
        eat(philo);
        routine_sleep(philo);
        thinks(philo);
    }
    return NULL;
}

void    philo_init(t_philosophe *philo,t_info_table *info, int i)
{
    philo->id = i + 1;
    philo->max_meal = false;
    philo->time_to_die = info->time_to_die;
    philo->time_to_eat = info->time_to_eat;
    philo->time_to_sleep = info->time_to_eat;
    philo->fork_left = &info->forks[i];
    philo->fork_right = &info->forks[(i + 1) % info->nb_philo];

}

int create_philo(t_info_table *info)
{
    int i;

    i = 0;

    while(i < info->nb_philo)
    {
        philo_init(&info->philos[i], info, i);
        pthread_create(&info->philos[i].thread, NULL, &philo_routine,(void *)&info->philos[i]);
        i++;
    }
    return 0;
}
