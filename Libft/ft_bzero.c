/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:28:53 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 13:39:19 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;
    
    ptr = s;

    while(n--)
    {
        *ptr++ = '\0';
    }
}
// /*int main() {

//     int test[6] = {1,2,3,4,5,6};
//     int     n;
//     int     i;
//     i = 0;
//     n = sizeof(int) * 6;
//     ft_bzero(test,n);
    
//     while(i < 6)
//     {
//         printf("%d ",test[i]);
//         i++;
//     }
// }/*
