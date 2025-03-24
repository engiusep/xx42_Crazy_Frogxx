#include "philo.h"


int eat(t_philosophe *philo)
{
    pthread_mutex_lock(philo->fork_right);
    printf("%d philo take fork\n",philo->id);
    pthread_mutex_lock(philo->fork_left);
    printf("%d philo take fork\n",philo->id);
    printf("%d philo eat\n",philo->id);
    usleep(philo->time_to_eat * 1000);
    pthread_mutex_unlock(philo->fork_right);
    pthread_mutex_unlock(philo->fork_left);
    return (0);
}

int routine_sleep(t_philosophe *philo)
{
    printf("%d philo sleep\n",philo->id);
    usleep(philo->time_to_sleep * 1000);
    return 0;
}
int thinks(t_philosophe *philo)
{
    printf("%d philo thinking\n",philo->id);
    return 0;
}