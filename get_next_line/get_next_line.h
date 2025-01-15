/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:38:47 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/08 11:34:48 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
void	take_exedent(char *str, char *buffer);
int		ft_check_line(char *str);
char	*take_the_line(char *str);
char	*ft_strjoin1(char *s1, char *s2);
int		ft_strlen1(char *str);
char	*build(int fd, char *str, char *buffer);

#endif
