/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:28:20 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 15:37:45 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int i;
	char	*str;
	i = 0;
	if(!s || !f)
		return NULL;
	str = malloc(ft_strlen((char *)s) + 1);
	if(!str)
		return (NULL);
	while(s[i])
	{
		str[i] = f(i,s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char to_upper(unsigned int i, char c)
// {
//     // Exemple simple : convertir en majuscule
//     if (c >= 'a' && c <= 'z')
//         return c - 32; // Conversion en majuscule
//     return c;
// }

// int main()
// {
//     char *str = "bonjour";
//     char *result = ft_strmapi(str, to_upper);
    
//     if (result) {
//         printf("Résultat : %s\n", result); // Affiche "BONJOUR"
//         free(result); // N'oublie pas de libérer la mémoire !
//     } else {
//         printf("Erreur d'allocation ou de paramètres\n");
//     }

//     return 0;
// }