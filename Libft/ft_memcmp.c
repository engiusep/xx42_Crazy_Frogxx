/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:17:43 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/14 13:04:03 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str;
	const unsigned char	*str2;

	str = s1;
	str2 = s2;
	while (n--)
	{
		if (*str != *str2)
			return (*str - *str2);
		str++;
		str2++;
	}
	return (0);
}
// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main() {
//     int array1 [] = { 54, 85, 20, 63, 21 };
//     int array2 [] = { 54, 85, 19, 63, 21 };
//     size_t size = sizeof( int ) * 5;
//     assert( memcmp( array1, array2, size) 
//== ft_memcmp( array1, array2, size) );       
//     assert( memcmp( array1, array1, size) 
//== ft_memcmp (array1, array1, size) );       
//     assert( memcmp( array2, array1, size) 
//== ft_memcmp( array2, array1, size) );       
//     printf( "Test is ok\n" );	
//     return 0;
// }