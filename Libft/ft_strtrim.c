/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:54:16 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/14 14:59:20 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	charisset(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int	index_start(char *s1, char *set)
{
	int	i;

	i = 0;
	while (charisset(s1[i], set))
	{
		i++;
	}
	return (i);
}

int	index_end(char *s1, char *set)
{
	int	i;

	i = 0;
	i = ft_strlen(s1) - 1;
	while (i >= 0 && charisset(s1[i], set))
	{
		i--;
	}
	return (i);
}

char	*ft_clean(char *str, char *s1, char *set)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	start = index_start((char *)s1, (char *)set);
	end = index_end((char *)s1, (char *)set);
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	start = index_start((char *)s1, (char *)set);
	end = index_end((char *)s1, (char *)set);
	if ((s1[0] == '\0') || (start > end))
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	return (ft_clean(str, (char *)s1, (char *)set));
}

//  int     main(void)
//  {
//      char *str = "/    salut  / /   /";
//      char *set = " /";
//      printf("%s\n",ft_strtrim(str,set));
//  }