/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:06:35 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/02 12:25:53 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}
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

	i = 0;
	if (!s1)
		s1 = "";
	if (s2[0] == 0)
		return (s2);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (*s1)
		ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}

int	ft_check_line(char *str)
{
	if(str == NULL)
		return (0);
	while(*str)
	{
		if(*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int 	i;
	int			nb_bytes;
	char	buffer[BUFFER_SIZE + 1];
	char		*str;
	static  char		*new;
	static char *temp_new;
	
	nb_bytes = 0;
	i = 0;
	buffer[0] = 0;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	while (ft_check_line(new) == 0)
	{
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		if(nb_bytes <= 0)
			break;
		buffer[nb_bytes] = '\0';
		new = ft_strjoin(new, buffer);
		free(temp_new);
		temp_new = new;
	}
	if(buffer[0] == '\0')
			return (NULL);
	str = malloc(ft_strlen2(new) + 2);	
	if(!str)
	{
		free(temp_new);
		temp_new = NULL;
		return NULL;
	}
	while(*new && *new != '\n')
		str[i++] = *new++;
	if(*new && *new == '\n')
	{
		str[i++] = '\n';
		new++;
	}
	str[i] = '\0';
	if(str[0] == 0)
	{
		
		free(str);
		free(temp_new);
		temp_new = NULL;
		return NULL;
	}
	return (str);
}

// int	main(){
	
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
// 	// // str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// 	close(fd);
//  }
