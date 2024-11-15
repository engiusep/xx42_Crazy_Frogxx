/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:04:38 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/15 17:43:06 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"
#include "../Libft/libft.h"

void ft_putstr(char const *str)
{
	int	i;
	i = 0;
	while(str[i])
	{
		putchar(str[i]);
		i++;
	}
}
int	ft_printf(const char *str, ...)
{
 	va_list args;
 	va_start(args,str);
	int	i;
	i = 0;
	while(*str)
	{
		if(*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				putchar(va_arg(args,int));	
			}
			else if (*str == 's')
			{
				ft_putstr(va_arg(args,char *));
			}
			else if(*str == 'd' || *str == 'i' || *str == 'u')
			{
				ft_putnbr_fd(va_arg(args,int),1);
			}
		}
		 else
		 {
		 	write(1,&*str,1);
		 }
		 str++;
	}
	
	return i;
}
 int	main()
{
 	ft_printf("salut %lu ", 23, "salut");
}