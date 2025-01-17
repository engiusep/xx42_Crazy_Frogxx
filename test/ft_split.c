/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:58:48 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/22 13:55:30 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_is_sep(char str, char c)
{
	if (str == c)
		return (1);
	if (str == '\0')
		return (1);
	return (0);
}

int	count_word(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (char_is_sep(str[i], c) == 0 && char_is_sep(str[i + 1], c) == 1)
			count++;
		i++;
	}
	return (count);
}

char	*allo_cpy(char *str, char c)
{
	int		i;
	char	*new;
	int		len;

	i = 0;
	len = 0;
	while (str[len] && !char_is_sep(str[len], c))
		len++;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	free_all(char **split, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		nb;
	int		j;

	j = 0;
	nb = count_word((char *)s, c);
	str = malloc((nb + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (j < nb)
	{
		while (char_is_sep(*s, c) == 1)
			s++;
		str[j] = allo_cpy((char *)s, c);
		if (!str[j])
		{
			free_all(str, j);
			return (NULL);
		}
		while (char_is_sep(*s, c) == 0)
			s++;
		j++;
	}
	str[j] = NULL;
	return (str);
}
