/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:06:35 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/19 17:38:55 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int 	ft_strlen(char *str)
{
	int i;
	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	if(str[i] == '\n')
		i++;
	return (i);
}
char *ft_parse(char *line) 
{
	int j;
	static int i;
	j = 0;
    char *new;
	new = NULL;
	
	if (!line || line[i] == '\0')
        return NULL;
    new = malloc((ft_strlen(line) + 2));
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
	static char buffer[BUFFER_SIZE + 1];
	char *str;
	nb_bytes = 0;
	
	nb_bytes = read(fd,buffer,BUFFER_SIZE);
	if(nb_bytes < 0)
		return (NULL);
	str = ft_parse(buffer);
	return (str);
}


// int	main()
// {
// 	 char* fileName = "hello.txt";
// 	 int fd = open(fileName,O_RDWR);
// 	 char *str;
// 	str = get_next_line(fd);
// 	 printf("%s",str);
// 	 free (str);
// 	str = get_next_line(fd);
// 	printf("%s",str);
// 	free (str);
// 	str = get_next_line(fd);
// 	 printf("%s",str);
// 	 free (str);
	//  str = get_next_line(fd);
	//  printf("%s",str);
	//  free (str);
	//  str = get_next_line(fd);
	//  printf("%s",str);
	//  free (str);
// }

//   while(buffer[i] != '\n')
	//   {
	// 	ft_putchar(buffer[i]);
	// 	i++;
	//   }