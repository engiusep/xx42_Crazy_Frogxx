/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:27:45 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/02 18:01:32 by engiusep         ###   ########.fr       */
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
	line = recup_the_line(str);
	if (!line)
		return (free(str), NULL);
	if (line[0] == 0)
		return (free(line), free(str), NULL);
	recup_exedent(str, buffer);
	return (free(str), line);
}

// int	main(void)
// {
// 	int fd = 0;
// 	char	*str;

// 	fd = open("hello.txt", O_RDONLY);
// 	while(1)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s",str);
// 		if (!str)
// 			break ;
// 		free(str);
// 	}
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	close(fd);
// }

// read -> buffer , tant que yq des trucs dans buffer -> strjoin line et buffer

// tronquer line a partir de \n

// //buffer = buffer d apres \n
// salut ca va 100/
// impossible