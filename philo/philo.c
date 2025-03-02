#include "philo.h"

void *routine(void *arg)
{
    t_philosophe *philo  = (t_philosophe *)arg;
    int i;
    i = 0;
    while(1)
    {
        printf("Philo %d pense\n",philo->id);
        usleep(1000 * (rand() % 500));

        if(philo->id % 2 == 0)
        {
            pthread_mutex_lock(philo->fork_right);
            printf("Philo %d a pris la fork right\n",philo->id);
            pthread_mutex_lock(philo->fork_left);
            printf("Philo %d a pris la fork letf\n",philo->id);
            i = 1;
        }
        else
        {
            pthread_mutex_lock(philo->fork_left);
            printf("Philo %d a pris la fork left\n",philo->id);
            pthread_mutex_lock(philo->fork_right);
            printf("Philo %d a pris la fork right\n",philo->id);
            i = 2;
        }
        printf("Philo %d mange\n",philo->id);
        usleep(1000 * (rand() % 500));
        if(i == 1)
        {
            pthread_mutex_unlock(philo->fork_left);
            pthread_mutex_unlock(philo->fork_right);
            printf("Philo %d a poser les fork\n",philo->id);
        }
        else
        {
            pthread_mutex_unlock(philo->fork_right);
            pthread_mutex_unlock(philo->fork_left);
            printf("Philo %d a poser les fork\n",philo->id);
        }

        printf("Philo %d dort\n",philo->id);
        usleep(1000 * (rand() % 500));
    }
    return NULL;
}

int main(int argc, char **argv)
{
    int i;
    i = 0;
    pthread_t thread;
    pthread_mutex_t fourchette[NB_PHILO];
    t_philosophe philosophe[NB_PHILO];
    while(i < NB_PHILO)
    {
        pthread_mutex_init(&fourchette[i],NULL);
        i++;
    }
    i = 0;
    while(i < NB_PHILO)
    {
        philosophe[i].id = i;
        philosophe[i].fork_left = &fourchette[i];
        philosophe[i].fork_right = &fourchette[(i + 1) % NB_PHILO];
        pthread_create(&thread, NULL, routine, (void *)&philosophe[i]);
        i++;
    }
    i = 0;
    while(i < NB_PHILO)
    {
        pthread_join(thread, NULL);
        i++;
    }

    return 0;
}
