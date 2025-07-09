#include "philo.h"
int init_philo(t_data *data, t_philo **philos)
{
    int i;

    i = 0;
    *philos = malloc(sizeof(t_philo) * data->nb_philo);
    if(!(*philos))
        return (-1);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
    if(!data->forks)
        return (-1);
   i = 0;
    while (i < data->nb_philo)
    {
	    pthread_mutex_init(&data->forks[i], NULL);
	    (*philos)[i].id = i + 1;
	    (*philos)[i].meals_count = 0;
	    (*philos)[i].last_meal_time = 0;
	    (*philos)[i].left_fork = &data->forks[i];
	    (*philos)[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
	    (*philos)[i].data = data;
	    i++;
    }
    return (0);
}

int check_data(t_data *data)
{
    if(data->nb_philo < 0 || data->time_to_die < 0|| data->time_to_eat < 0 || data->time_to_sleep < 0)
        {
            printf("Error: put a positive number\n");
            exit(EXIT_FAILURE);
        }
    return (0);
}
int init_data(t_data *data,int argc,char **argv)
{
           if(argc != 5 && argc != 6)
        {
                printf("wrong input\n");
                exit(EXIT_FAILURE);
        }
        data->nb_philo = ft_atoi(argv[1]);
        data->someone_died = 0;
        data->time_to_die = ft_atoi(argv[2]);
        data->time_to_eat = ft_atoi(argv[3]);
        data->time_to_sleep = ft_atoi(argv[4]);
        if(argc == 6)
                data->nb_reach_meal = ft_atoi(argv[5]);
        else
                data->nb_reach_meal = -1;
        data->start_time = 0;
        check_data(data);
        return (0);
}

int main(int argc, char **argv)
{
    t_data data;
    t_philo *philos;
    int i;

    i = 0;
   init_data(&data,argc,argv);
   if(init_philo(&data,&philos) == -1)
        return (-1);

    while(i < data.nb_philo)
    {
        pthread_create(&philos[i].thread,NULL,&routine_philo, &philos[i]);
        i++;
    }
    free(philos);
    free(data.forks);
}