#include "philo.h"

void *routine_philo(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    
    while(!philo->data->someone_died)
    {
        printf("%ld philo[%d] thinking\n",get_time_ms() - philo->data->start_time,philo->id);
        pthread_mutex_lock(philo->right_fork);
        pthread_mutex_lock(philo->left_fork);
        printf("%ld philo[%d] eating\n",get_time_ms() - philo->data->start_time,philo->id);
        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);
        printf("%ld philo[%d] sleeping\n",get_time_ms() - philo->data->start_time,philo->id);
        usleep(philo->data->time_to_sleep * 1000);
    }
    return (NULL);
}