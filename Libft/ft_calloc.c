/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:39:53 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 17:22:11 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    unsigned char *ptr;
    int i;
    i = 0;
    
    ptr = malloc(nmemb * size);
    if(!ptr)
        return(NULL);
    ft_bzero(ptr,(nmemb * size));
    return ((void*)ptr);
}