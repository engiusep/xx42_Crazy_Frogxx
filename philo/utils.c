#include "philo.h"

int ft_atoi(char *str)
{
    int nb;
    int count;
    int i;
    nb = 0;
    count = 0;
    i = 0;

    while((str[i] > 9 && str[i] < 13) || str[i] == 32)
        i++;
    
    while(str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - 48);
        i++;
    }
    return (nb);
}
