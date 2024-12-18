/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:03:23 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/10 17:07:31 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*build(int fd, char *str, char *buffer)
{
	int	nb_nytes;

	nb_nytes = 1;
	while (ft_check_line(buffer) == 0 && nb_nytes != 0)
	{
		nb_nytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_nytes < 0)
		{
			buffer[0] = 0;
			return (free(str), NULL);
		}
		buffer[nb_nytes] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[NB_FD][BUFFER_SIZE + 1];
	char		*line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = 0;
	str = ft_strjoin(str, buffer[fd]);
	if (!str)
		return (free(str), NULL);
	str = build(fd, str, buffer[fd]);
	if (!str)
		return (NULL);
	line = take_the_line(str);
	if (!line)
		return (free(str), NULL);
	if (line[0] == 0)
		return (free(line), free(str), NULL);
	take_exedent(str, buffer[fd]);
	return (free(str), line);
}
