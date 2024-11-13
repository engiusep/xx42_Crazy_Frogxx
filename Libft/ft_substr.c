/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:01:19 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 15:32:47 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char *ft_substr(char const *s, unsigned int start,size_t len)
{
    int i;
    char *ptr;
    i = 0;
    if(start >= ft_strlen(s))
    {
        ptr = malloc(1);
        if(!ptr)
            return(ptr);
        ptr[0] = 0;
        return (ptr);
    }
    ptr = malloc(len+ 1);
    if(!ptr)
        return(NULL);
    while(i < len)
    {
        ptr[i] = s[start + i];
        i++; 
    }
    ptr[i] = '\0';
    return(ptr);
    
}
// // #include <ctype.h>
// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <string.h>


// int main(void)
// {
//     char *str = "salut ca va ";
  
    
//      printf("test ; %s ",ft_substr(str,50,10));
//  }