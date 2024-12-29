/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:27:45 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/29 15:01:21 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = 0;
	str = ft_strjoin(str, buffer);
	if (!str)
		return (free(str), NULL);
	str = build(fd, str, buffer);
	if (!str)
		return (NULL);
	line = take_the_line(str);
	if (!line)
		return (free(str), NULL);
	if (line[0] == 0)
		return (free(line), free(str), NULL);
	take_exedent(str, buffer);
	return (free(str), line);
}
// #include <stdio.h>

// int main()
// {
// 	int fd;
// 	int fd2;
// 	char *str;
// 	char *str2;

// 	fd = open("hello.txt",O_RDONLY);
// 	fd2 = open("hello.txt",O_RDONLY);
// 	while(str != NULL)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s",str);
// 		free(str);
// 	}
// 	while(str2 != NULL)
// 	{
// 		str = get_next_line(fd2);
// 		printf("%s",str2);
// 		free(str2);
// 	}
// }