#include "philo.h"



int    check_arg(t_info_table *info, int argc, char **argv)
{
    if(argc == 5 || argc == 6)
    {
        info->nb_philo = ft_atoi(argv[1]);
        info->time_to_die = ft_atoi(argv[2]);
        info->time_to_eat = ft_atoi(argv[3]);
        info->time_to_sleep = ft_atoi(argv[4]);
        if(argc == 6)
            info->number_meal = ft_atoi(argv[5]);
        else
            info->number_meal = INT_MAX;
    }
    else
        return -1;
    return 0;
}

void data_init(t_info_table *info)
{
    info->end_prog = false;
    info->number_meal = 0;
}

int main(int argc,char **argv)
{
    t_info_table info;
    if(check_arg(&info, argc, argv) == -1)
        return (-1);
    info.philos = malloc(sizeof(t_philosophe) * info.nb_philo);
    info.forks = malloc(sizeof(pthread_mutex_t) * info.nb_philo);
    data_init(&info);
    create_forks(&info);
    create_philo(&info);
}
