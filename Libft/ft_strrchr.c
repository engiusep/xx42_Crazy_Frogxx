/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:53:18 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/14 14:22:23 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = ft_strlen(s) - 1;
	j = i + 1;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	if ((char)c == '\0')
		return ((char *)s + j);
	return (NULL);
}
//    int main()
//  {
//        const char str[10] = "saluta";          
//        char c = '\0';
//      const char str2[10] = "saluta";
//       char ca = '\0';	
//       printf("%s\n",ft_strrchr(str,c));
//       printf("%s\n",strrchr(str2,ca));
//  }