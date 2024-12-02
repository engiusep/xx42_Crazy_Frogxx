/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:27:45 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/02 16:45:30 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "get_next_line.h"

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
	char *new;
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

char *recup_the_line(char *str)
{
	char *line;
	int i;
	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while(*str && *str != '\n')
		line[i++] = *str++;
	if(*str == '\n')	
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

int	ft_check_line(char *str)
{
	if(str[0] == 0 || !str)
		return (0);
	while(*str)
	{
		if(*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
void recup_exedent(char *str,char *buffer)
{
	int i;
	i = 0;
	while(*str && *str != '\n')
		str++;
	if(*str == '\n')
		str++;
	while(*str)
		buffer[i++] = *str++;
	buffer[i] = '\0';
}
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char *line;
	char *str;
	int nb_nytes;

	nb_nytes = 1;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(1);
	if(!str)
		return (NULL);
	str[0] = 0;
	str = ft_strjoin(str, buffer);
	if (!str)
		return (free(str),NULL);
	while (ft_check_line(buffer) == 0 && nb_nytes != 0)
	{
		nb_nytes = read(fd,buffer,BUFFER_SIZE);
		if(nb_nytes < 0)
			return (free(str),buffer[0] = 0,NULL);
		buffer[nb_nytes] = '\0';
		str = ft_strjoin(str,buffer);
		if (!str)
			return (NULL);
	}
	line = recup_the_line(str);
	if (!line)
		return (free(str),NULL);
	if (line[0] == 0)
		return (free(line),free(str),NULL);
	recup_exedent(str,buffer);
	return(free(str),line);
}
int	main()
{	
	int fd = 0;
	char	*str;

	fd = open("hello.txt", O_RDONLY);
	while(1)
	{	
		str = get_next_line(fd);
		printf("%s",str);
		if (!str)
			break ;
		free(str);
	}
	close(fd);
}

//read -> buffer , tant que yq des trucs dans buffer -> strjoin line et buffer

// tronquer line a partir de \n

// //buffer = buffer d apres \n
// salut ca va 100/
// impossible 