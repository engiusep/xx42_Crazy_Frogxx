/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:19:24 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/05 15:34:29 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
int ft_strlen(char *str)
{
    int i;
    i = 0;

    while(str[i])
        i++;
    return(i);
}
int ft_strlcpy(char *dst, const char *src, size_t size)
{
    int i;
    i = 0;
    while(src[i] && i < (size - 1))
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return(ft_strlen(dst));    
}

int main(void)
{
    char dst[15] = "salut ca va";
    char src[15] = "bie etoi";
    
    printf("%d\n",ft_strlcpy(dst,src,4));
}