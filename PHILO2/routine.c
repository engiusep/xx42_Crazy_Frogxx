#include "philo.h"

void *routine_philo(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while(!philo->data->someone_died)
    {
        printf("%ld philo[%d] thinking\n",get_time_ms() - philo->data->start_time,philo->id);
        if(philo->id % 2 == 0)
        {
            pthread_mutex_lock(philo->right_fork);
            printf("%ld philo[%d] as taken a fork\n",get_time_ms() - philo->data->start_time,philo->id);
            pthread_mutex_lock(philo->left_fork);
            printf("%ld philo[%d] as taken a fork\n",get_time_ms() - philo->data->start_time,philo->id);
        }
        else
        {
            pthread_mutex_lock(philo->left_fork);
            printf("%ld philo[%d] as taken a fork\n",get_time_ms() - philo->data->start_time,philo->id);
            pthread_mutex_lock(philo->right_fork);
            printf("%ld philo[%d] as taken a fork\n",get_time_ms() - philo->data->start_time,philo->id);
        }
        philo->last_meal_time = get_time_ms();
        printf("%ld philo[%d] eating\n",get_time_ms() - philo->data->start_time,philo->id);
        usleep(philo->data->time_to_eat * 1000);
        philo->meals_count++;

        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);

        printf("%ld philo[%d] sleeping\n",get_time_ms() - philo->data->start_time,philo->id);
        usleep(philo->data->time_to_sleep * 1000);
    }
    return (NULL);
}