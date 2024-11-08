/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:48:43 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/06 10:54:24 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
    n--;
	while (s1[i] != '\0' && s2[i] != '\0' && n != 0)
	{
        if (s1[i] != s2[i])
		    return (s1[i] - s2[i]);
		i++;
        n--;
	}
	return (0);
}
int main(void)
{
    char *str = "salt";
    char *str2 = "salut";
    
    printf("%d",ft_strncmp(str,str2,5));
}