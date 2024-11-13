/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:06:28 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 13:42:14 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
void ft_putendl_fd(char *s, int fd)
{
    char c;
    int i;
    i = 0;
    c = '\n';
    while(s[i])
    {
        write(fd, &s[i],1);
        i++;
    }
    write(fd, &c,1);
}

// int main(void)
// {
//     int fd;
//     char *str;
//     str = "salut ca va";
//     fd = open("test.txt",O_WRONLY);
//     ft_putendl_fd(str,fd);
// }