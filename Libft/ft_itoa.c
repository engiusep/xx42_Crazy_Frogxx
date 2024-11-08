/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:32:08 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/07 13:27:41 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int strlenint(int nb)
{
    int count;
    
    count = 0;
    if(nb == 0)
        count++;
        
    while(nb != 0)
    {
        nb = nb / 10;
        count++;
    }
    return (count);
}

char    *ft_itoa(int n)
{
    int len;
    char *str;
    int   i;
    
    i = 0;
    len = strlenint(n);
    str = malloc(len + 1);
    if(n < 0)
    {
        len++;
        n = -n;
        str[0] = '-';
    }
    if(n == 0)
    {
        str[0] = '0';
        return (str);
    }
    while(n != 0)
    {
        str[len - 1 - i] = (n % 10) + '0';
        n = n / 10;
        i++;
    }
    str[len] = '\0';
    return (str);
}

int main(void)
{
    printf("%s",ft_itoa(235));
}