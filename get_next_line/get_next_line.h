/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:07:01 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/19 17:35:27 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_list
{
	int	i;
	int j;
	
	char *line;
	ssize_t nb_bytes;
}	t_gnl;

char *get_next_line(int fd);
char *ft_parse(char *line);
int 	ft_strlen(char *str);
#endif