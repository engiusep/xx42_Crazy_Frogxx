/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:35:03 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/05 15:57:07 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
unsigned int ft_strlen(char *str)
{
    unsigned int i;

    i = 0;
    while (str[i] != '\0')
    i++;
    return (i);
}

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && nb != 1)
    {
        dest[i] = src[j];
        i++;
        j++;
        nb--;
    }
    dest[i] = '\0';
    return (dest);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int i;
    unsigned int dest_len;

    i = 0;
    dest_len = ft_strlen(dest);
    if (size <= dest_len)
    {
        return (ft_strlen(src) + size);
    }
    else
    {
        ft_strncat(dest, src, (size - dest_len));
        return (dest_len + ft_strlen(src));
    }
}
int main()
{
    char dest[7] = "jour";
    char src[] = "jour";
    char dest2[7] = "jour";
    char src2[] = "jour";
    unsigned int i = 2;
    unsigned int j = 2;

    printf("%d\n", ft_strlcat(dest, src, i));
    printf("%zu\n", strlcat(dest2, src2, j));
    printf("%s\n", dest);
    printf("%s\n", dest2);
}