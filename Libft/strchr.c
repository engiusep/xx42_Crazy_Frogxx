/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:39:55 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/05 16:52:11 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strchr(const char *s, int c)
{
    while(*s)
    {
        if(*s == c)
            return ((char *)s);
        s++;
    }
    if(c == '\0')
        return ((char *)s);
    return NULL;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    const char str[10] = "salut";
    char c = 'l';
    
    printf("%s\n",ft_strchr(str,c));
}