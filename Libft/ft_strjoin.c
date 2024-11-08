/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:52:45 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/06 15:02:27 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    int i;
    char *ptr;
    i = 0;
    ptr = malloc(strlen(s1) + strlen(s2) + 1);
    
    while(*s1)
    {
        ptr[i] = *s1;
        i++;
        s1++;
    }
    while(*s2)
    {
        ptr[i] = *s2;
        s2++;
        i++;
    }
    ptr[i] = '\0';
    return(ptr);
}

int main(void)
{
    char const *str = "salut";
    char const *str2 = "cava";
    
    printf("%s",ft_strjoin(str,str2));
}