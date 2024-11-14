/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:52:45 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/14 14:12:58 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*ptr;
	int		i;

	i = 0;
	size = ft_strlen(s);
	ptr = malloc(size * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main() {
//     const char * original = "The original string.";
//     // On duplique la chaîne de caractères initiale.
//     char * copy = ft_strdup( original );
//     // On passe chaque lettre en majuscule.
//     char * ptr = copy;
//     while( *ptr != '\0' ) {
//         *ptr = toupper( *ptr );
//         ptr++;
//     }
//     // On affiche la chaîne finale
//     printf( "%s\n", copy );
//     // Sans oublier de libérer l'espace mémoire au final.
//     free( copy );
//     return EXIT_SUCCESS;
// }