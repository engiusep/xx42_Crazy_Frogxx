/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:34:48 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 14:37:29 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include	<string.h>
char *ft_strnstr(const char *big, const char *little, size_t len)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    
    if(*little == '\0')
        return ((char *)big);
    while(big[i] && len > i)
    {
        j = 0;
        while(little[j] == big [i + j] && i + j < len)
        {
            if(little[j + 1] == '\0')
            {
                return ((char *)big + i);
            }
            j++;
        }
        i++;
    } 
    return NULL;
}
//  #include <stdio.h>
//  #include <stdlib.h>
//  #include <string.h>


//  int main() 
//  {
//      const char *str = "sallut";
//     const char *str2 = "";
    
//      printf("%s",ft_strnstr(str,str2,10));
//     //printf("%d",strnstr(str,str2,10));
//  }