#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <limits.h>
#include <sys/time.h>
#include <stdbool.h> 

typedef struct s_philosophe
{
    pthread_t thread;
    int id;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    
    int all_eat;
    int number_meal;
    int eat;
    int last_meal;
    bool max_meal;
    pthread_mutex_t *fork_left;
    pthread_mutex_t *fork_right;
} t_philosophe;

typedef struct s_info_table
{
    int nb_philo;
    int time_to_eat;
    int time_to_die;
    int time_to_sleep;
    int number_meal;
    int start_prog;
    bool end_prog;
    t_philosophe *philos;
    pthread_mutex_t *forks;
}t_info_table;

int ft_atoi(char *str);
int eat(t_philosophe *philo);
int routine_sleep(t_philosophe *philo);
int thinks(t_philosophe *philo);
void    create_forks(t_info_table *info);
int create_philo(t_info_table *info);
#endif