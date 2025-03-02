#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

# ifndef NB_PHILO
# define NB_PHILO 10
# endif

typedef struct s_philosophe
{
    int id;
    pthread_mutex_t *fork_left;
    pthread_mutex_t *fork_right;
} t_philosophe;

#endif