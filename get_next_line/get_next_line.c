/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:06:35 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/20 14:30:41 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int 	ft_strlen(char  *str)
{
	int i;
	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	if(str[i] == '\n')
		i++;
	return (i);
}
char	*ft_strjoin(char *s1, char  *s2)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!s1)
        s1 = "";
    if (!s2)
        s2 = "";
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (*s1)
	{
		ptr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		ptr[i] = *s2;
		s2++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char *ft_parse(char *line) 
{
	int j;
	static int i;
	j = 0;
    char *new;
	
	if (!line || line[i] == '\0')
        return NULL;
    new = malloc((ft_strlen(line) + 1));
    if (!new)
        return NULL; 
    while (line[i] && line[i] != '\n') 
	{
        new[j] = line[i]; 
        i++;
        j++;
    }
	if(line[i] == '\n')
	{
		new[j] = line[i];
		i++;
		j++;
	}
    new[j] = '\0';
	return (new);
}

char *get_next_line(int fd)
{
	int nb_bytes;
	static char buffer[1000];
	char *str = malloc(1000);
	char *new = malloc(1000);
	new = NULL;
	nb_bytes = 0;
	
	while((nb_bytes = read(fd,buffer,BUFFER_SIZE)) > 0)
	{
		str = ft_parse(buffer);
		new = ft_strjoin(str,new);
	}
	//if(nb_bytes < 0)
	//	return (NULL);
	return (new);
}

int	main()
{
	 int fd = open("hello.txt",O_RDONLY);
	 
	 char *str;
	str = get_next_line(fd);
	 printf("%s",str);
	 free (str);
	str = get_next_line(fd);
	printf("%s",str);
	free (str);
	str = get_next_line(fd);
	 printf("%s",str);
	 free (str);
	 str = get_next_line(fd);
	 printf("%s",str);
	 free (str);
	 str = get_next_line(fd);
	 printf("%s",str);
	 free (str);
}
//   while(buffer[i] != '\n')
	//   {
	// 	ft_putchar(buffer[i]);
	// 	i++;
	//   }