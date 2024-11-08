/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:01:19 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/06 14:50:26 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start,size_t len)
{
    int i;
    char *ptr;
    i = 0;
    ptr = malloc(len * sizeof(char) + 1);
    while(i < len)
    {
        ptr[i] = s[start + i];
        i++; 
    }
    ptr[i] = '\0';
    return(ptr);
    
}
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    char *str = "salut ca va ";
  
    
    printf("%s",ft_substr(str,5,10));
}