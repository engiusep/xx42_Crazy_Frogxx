/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:38:47 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/02 15:39:27 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd);
void recup_exedent(char *str,char *buffer);
int	ft_check_line(char *str);
char *recup_the_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(char *str);