/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:54:52 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 17:31:45 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
void *ft_memchr(const void *s, int c, size_t n)
{
    char const *ptr;
    ptr = s;
    
    while(*ptr && n--)
    {
        if(*ptr == c)
            return ((void *)ptr);
        ptr++;
    }
    if(*ptr == c && c == '\0')
        return ((void *)ptr);
    return NULL;
}

// int main() {

//     char data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
//     const unsigned int size = 10;

//     // On recherche une valeur inhéxistante :
//     void * found = ft_memchr( data, 57, size );
//     printf( "57 is %s\n", ( found != NULL ? "found" : "not found" ) );

//     // On recherche une valeur existante :
//     found = ft_memchr( data, 50, size );
//     printf( "50 is %s\n", ( found != NULL ? "found" : "not found" ) );
//     if ( found != NULL ) {
//         printf( "La valeur à la position calculée est %d\n", *((char *) found) );
//     }

//     return EXIT_SUCCESS;
// }