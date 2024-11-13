/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:35:03 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 15:19:34 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char *ft_strncat(char *d, const char *s, unsigned int nb)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (d[i] != '\0')
        i++;
    while (s[j] != '\0' && nb != 1)
    {
        d[i] = s[j];
        i++;
        j++;
        nb--;
    }
    d[i] = '\0';
    return (d);
}

size_t ft_strlcat(char *d, const char *s, size_t dstsize)
{
    size_t i;
    size_t dest_len;

    i = 0;
    dest_len = ft_strlen(d);
    if (dstsize <= dest_len)
    {
        return (ft_strlen(s) + dstsize);
    }
    else
    {
        ft_strncat(d, s, (dstsize - dest_len));
        return (dest_len + ft_strlen(s));
    }
}
// int main()
// {
//     char dest[7] = "jour";
//     char src[] = "jour";
//     char dest2[7] = "jour";
//     char src2[] = "jour";
//     unsigned int i = 2;
//     unsigned int j = 2;

//     printf("%d\n", ft_strlcat(dest, src, i));
//     printf("%zu\n", strlcat(dest2, src2, j));
//     printf("%s\n", dest);
//     printf("%s\n", dest2);
// }