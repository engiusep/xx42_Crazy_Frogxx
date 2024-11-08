/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:40:31 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/07 15:00:53 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
void ft_putchar_fd(char c, int fd)
{
    write(fd, &c,1);
}

int main(void)
{
    int fd;
    fd = open("test.txt",O_WRONLY);
    ft_putchar_fd('A',fd);
    close(fd);
}