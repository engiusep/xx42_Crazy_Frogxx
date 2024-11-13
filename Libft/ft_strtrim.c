/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:54:16 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 15:54:29 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int charisset(char c,char *set)
{
    while(c == *set)
    {
        return (1);
        set++;
    }
    return (0);
}

int Index_start(char *s1,char *set)
{
    int i;
    i = 0;
    while(charisset(s1[i],set))
    {
        i++;
    }
    return (i);
}
int Index_end(char *s1,char *set)
{
    int i;
    i = 0;
    i = ft_strlen(s1) - 1;
    while(i >= 0 && charisset(s1[i],set))
    {
        i--;
    }
    return (i);
}


char *ft_strtrim(char const *s1, char const *set)
{
    int i;
    char *str;
    int start;
    int end;
    i = 0;
    start = Index_start((char *)s1,(char *)set);
    end = Index_end((char *)s1,(char *)set);
    if(start == ft_strlen((char *)s1))
    {
        if(!str)
            return NULL;
        str = malloc(1);
        str[i] = '\0';
        return (str);        
    }
    str = malloc(end - start + 2);
    if(!str)
        return NULL;
    
    while(start <= end)
    {
        str[i] = s1[start];
        i++;
        start++;
    }
    str[i] = '\0';
    return (str);
    
}

// int     main(void)
// {
//     char *str = "    salut      ";
//     char *set = "            ";
//     printf("%s",ft_strtrim(str,set));
// }