/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:01:19 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/14 15:20:49 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (start >= ft_strlen(s))
	{
		ptr = malloc(1);
		if (!ptr)
			return (ptr);
		ptr[0] = 0;
		return (ptr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
// // #include <ctype.h>
// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <string.h>
// int main(void)
// {
//     char *str = "salut ca va ";	
//      printf("test ; %s ",ft_substr(str,50,10));
//  }