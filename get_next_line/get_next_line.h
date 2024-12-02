/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:38:47 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/02 18:05:10 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	recup_exedent(char *str, char *buffer);
int		ft_check_line(char *str);
char	*recup_the_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*build(int fd, char *str, char *buffer);

#endif