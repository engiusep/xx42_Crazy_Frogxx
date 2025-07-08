#include "../philo.h"

int ft_atoi(const char *str)
{
    long num = 0;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        if (num > INT_MAX)
            return (-1);
        i++;
    }
    if (str[i] != '\0')
        return (-1);
    return (int)num;
}
