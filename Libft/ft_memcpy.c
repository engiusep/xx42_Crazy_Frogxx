/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:47:00 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/14 13:12:02 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;
	const char		*ptr_src;

	ptr_src = src;
	ptr = dest;
	if (((unsigned char *)dest == (void *)0)
		&& ((const char *)src == (void *)0))
		return (NULL);
	while (n--)
	{
		*ptr++ = (const char)*ptr_src++;
	}
	return (dest);
}

// int main() {
//     int array [] = { 54, 85, 20, 63, 21 };
//     int * copy = NULL;
//     int length = sizeof( int ) * 5;   
//     /* Memory allocation and copy */
//     copy = (int *) malloc( length );
//     ft_memcpy( copy, array, length );	
//     /* Display the copied values */
//     for( length=0; length<5; length++ ) {
//         printf( "%d ", copy[ length ] );
//     }
//     printf( "\n" );	
//     free( copy );	
//     return EXIT_SUCCESS;
// }
