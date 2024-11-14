/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:39:55 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/14 14:11:54 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}
//   #include <stdio.h>
//     #include <stdlib.h>
//   #include <string.h>
//   int main()
//   {
//       const char str[10] = "salut";
//       char c = '\0';
//       printf("%s\n",ft_strchr(str,c));
//   }