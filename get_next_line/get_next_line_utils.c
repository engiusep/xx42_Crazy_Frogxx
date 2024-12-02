/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:56:08 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/02 18:01:12 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*ptr;
	char	*new;

	new = s1;
	i = 0;
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (free(s1), NULL);
	while (*s1)
		ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	free(new);
	return (ptr);
}

char	*recup_the_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (*str && *str != '\n')
		line[i++] = *str++;
	if (*str == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

int	ft_check_line(char *str)
{
	if (str[0] == 0 || !str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

void	recup_exedent(char *str, char *buffer)
{
	int	i;

	i = 0;
	while (*str && *str != '\n')
		str++;
	if (*str == '\n')
		str++;
	while (*str)
		buffer[i++] = *str++;
	buffer[i] = '\0';
}
