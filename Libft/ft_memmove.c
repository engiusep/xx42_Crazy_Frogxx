/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:07:26 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 15:07:09 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char   *ptrdest;
    const unsigned char *ptrsrc;
    
    ptrdest = dest;
    ptrsrc = src;
    
    if(ptrdest != ptrsrc)
    {
        if(ptrdest < ptrsrc)
        {
            while(n--)
            *ptrdest++ = (const char)*ptrsrc++;
        }
        else
        {
            while(n--)
            ptrdest[n] = ptrsrc[n];
        }
    }
    return (dest);
} 


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define ELEMENT_COUNT 10

// int main() {

//     // On crée une zone de mémoire de 10 entiers et contenant
//     // que neuf valeurs. La dixième est non utilisée (0).
//     int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };

//     // On affiche le contenu de la collection
//     for( int i=0; i<ELEMENT_COUNT; i++ ) {
//         printf( "%d ", data[i] );
//     }
//     puts( "" );  // Un retour à la ligne

//     // On décale les éléménts dans la collection ...
//     void * source = (void *) data;
//     void * destination = (void *) ( data + 1 );
//     size_t size = ELEMENT_COUNT * sizeof( int );
//     memmove( destination, source, size );

//     // ... pour y insérer une nouvelle valeur en tête
//     data[0] = 10;

//     // On affiche le contenu de la collection
//     for( int i=0; i<ELEMENT_COUNT; i++ ) {
//         printf( "%d ", data[i] );
//     }
//     puts( "" );  // Un retour à la ligne

//     return EXIT_SUCCESS;
// }