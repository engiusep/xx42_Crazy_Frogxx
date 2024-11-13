/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:29:21 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 13:53:02 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *ptr;
    ptr = s;

    while (n--)
    {
        *ptr++ = (unsigned char)c;
    }
    return (s);
}