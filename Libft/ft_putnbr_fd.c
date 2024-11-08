/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:22:34 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/07 16:33:15 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c,1);
}
void ft_putnbr_fd(int n, int fd)
{

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-',fd);
		n = n * -1;
	}
	if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0',fd);
	else
	{
		ft_putnbr_fd(n / 10,fd);
		ft_putnbr_fd(n % 10,fd);
	}
}

int main(void)
{
    int fd;
    fd = open("test.txt",O_WRONLY);
    
    ft_putnbr_fd(1244,fd);
}