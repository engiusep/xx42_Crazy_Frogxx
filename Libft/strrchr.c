/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:53:18 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/05 17:16:10 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}
char *ft_strrchr(const char *s, int c)
{
    int i;
    
    i = ft_strlen(s) - 1;
    
    while(s[i - 1])
    {
        if(s[i] == c)
            return ((char *)(s + i));
        i--;
    }
        return NULL;   
}
int main()
{
    const char str[10] = "saluta";
    char c = 'a';
    const char str2[10] = "saluta";
    char ca = 'a';
    
    printf("%s\n",ft_strrchr(str,c));
    printf("%s\n",strrchr(str2,ca));
}