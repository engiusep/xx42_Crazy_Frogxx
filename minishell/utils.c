#include "minishell.h"

char *ft_strdup(char *str)
{
    int i;
    int size;
    char *new;
    
    size = 0;
    i = 0;
    while(str[size])
        size++;
    new = malloc(size * sizeof(char) + 1);

    while(str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}