/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:29:01 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 11:54:37 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int ft_atoi(const char *str)
{
    int number;
    int count;
    
    number = 0;
    count = 0;

    while(*str >= 9 && *str <= 13 || *str == 32)
        str++;
    
    if(*str == '-' || *str == '+')
    {
        if(*str == '-')
            count++;
        str++;
    }

    while(*str >= '0' && *str <= '9')
    {
        number = number * 10 - (*str - '0');
        str++;
    }

    if(count % 2 != 1)
    {
        return (-number);
    }
    return (number);
}

/*int main(void)
{
    printf("%d\n",ft_atoi("-1234"));
}*/