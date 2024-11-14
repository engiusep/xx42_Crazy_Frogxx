/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:33:17 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/14 14:14:29 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// #include <ctype.h>  // Pour la fonction toupper

// void to_upper_if_even(unsigned int i, char *c)
// {
//     if (i % 2 == 0)  // Si l'index est pair
//         *c = toupper(*c);  // Convertir le caractère en majuscule
// }
// int main()
// {
//     char str[] = "bonjour";
//     // Appliquer la fonction to_upper_if_even à chaque caractère de la chaîne
//     ft_striteri(str, to_upper_if_even);
//     printf("Résultat : %s\n", str);  // Affiche "BONjOuR"
//     return 0;
// }
