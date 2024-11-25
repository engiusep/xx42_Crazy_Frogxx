/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:04:38 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/25 16:01:07 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char const *str)
{
	int	i;
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	i = 0;
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_convert_base16(unsigned long long int nb)
{
	char	*base;
	int		size;

	base = "0123456789abcdef";
	size = 0;
	if (nb >= 16)
	{
		size += ft_convert_base16(nb / 16);
	}
	write(1, &base[nb % 16], 1);
	size++;
	return (size);
}

int	ft_putptr(void *ptr)
{
	int						size;
	unsigned long long int	ptr_nbr;

	size = 0;
	if (!ptr)
	{
		size += write(1, "(nil)", 5);
		return (size);
	}
	ptr_nbr = (unsigned long long int)(ptr);
	size += write(1, "0x", 2);
	size += ft_convert_base16(ptr_nbr);
	return (size);
}

int	check_arg(const char *str, va_list args)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (*str == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (*str == 'd' || *str == 'i')
		i += ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (*str == 'u')
		i += ft_putnbr(va_arg(args, int));
	else if (*str == 'x')
		i += ft_putnbr_base_unsigned((unsigned int)va_arg(args, int),
				"0123456789abcdef");
	else if (*str == 'X')
		i += ft_putnbr_base_unsigned((unsigned int)(va_arg(args, int)),
				"0123456789ABCDEF");
	else if (*str == '%')
		i += ft_putchar('%');
	else if (*str == 'p')
		i += ft_putptr(va_arg(args, void *));
	else
		return (-1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += check_arg(str, args);
		}
		else
			i += ft_putchar(*str);
		str++;
	}
	return (i);
}
