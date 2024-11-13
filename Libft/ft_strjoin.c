/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:52:45 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 15:35:19 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
char *ft_strjoin(char const *s1, char const *s2)
{
    int i;
    char *ptr;
    i = 0;
    ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if(!ptr)
        return (NULL);
    
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

// int main(void)
// {
//     char const *str = "salut";
//     char const *str2 = "cava";
    
//     printf("%s",ft_strjoin(str,str2));
// }