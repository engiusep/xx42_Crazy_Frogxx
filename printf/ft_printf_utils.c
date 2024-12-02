/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:52:22 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/29 15:47:44 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(unsigned int nb)
{
	unsigned int	count;

	count = 0;
	if (nb >= 0 && nb < 10)
		count += ft_putchar(nb + '0');
	else
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}

int	ft_putnbr_base(int nbr, const char *base)
{
	int	base_len;
	int	count;

	base_len = 0;
	count = 0;
	while (base[base_len] != '\0')
	{
		base_len++;
	}
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base_len)
	{
		count += ft_putnbr_base(nbr / base_len, base);
	}
	count += write(1, &base[nbr % base_len], 1);
	return (count);
}

int	ft_putnbr_base_unsigned(unsigned int nbr, const char *base)
{
	unsigned int	base_len;
	int				count;

	base_len = 0;
	count = 0;
	while (base[base_len] != '\0')
	{
		base_len++;
	}
	if (nbr >= base_len)
	{
		count += ft_putnbr_base(nbr / base_len, base);
	}
	count += write(1, &base[nbr % base_len], 1);
	return (count);
}
