/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:58:48 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/07 11:28:46 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charisep(char str,char c)
{
 
    if(str == c)
        return(1);
    if(str == '\0')
        return (1);
        
    return (0);
}

int countword(char *str,char c)
{
    int i;
    int count;
    count = 0;
    i = 0;
   while(str[i])
   {
        if(charisep(str[i],c) == 0 && charisep(str[i + 1],c) == 1)
            count++;
        i++;
   } 
    return (count);
}

char *allo_cpy(char *str,char c)
{
    int i;
    char *new;
    int len;
    i = 0;
    len = 0;
    while (str[len] && !charisep(str[len], c))
        len++;
    
    new = malloc(len + 1);
    while(i < len)
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
    
}

char **ft_split(char const *s, char c)
{
    char **str;
    int     nb;
    int     j;
    j = 0;
    nb = countword((char *)s,c);
    str = malloc((nb + 1) * sizeof(char *));

    while(j < nb)
    {
        while(charisep(*s,c) == 1)
            s++;
        str[j] = allo_cpy((char *)s,c);
        while(charisep(*s,c) == 0)
            s++;
        j++;
    }
    str[j] = NULL;
    return (str);    
    
}

int		main(int argc, char **argv)
{
	int i;
    char **str;

    str = ft_split(argv[1], argv[2][0]);
    i = 0;
    while (str[i])
        printf("%s\n", str[i++]);
    return (0);
}