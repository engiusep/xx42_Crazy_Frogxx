/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:04:38 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/18 18:34:15 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
int ft_putnbr_base(int nbr, const char *base)
{
    int base_len = 0;
	int count;
	count = 0;
    while (base[base_len] != '\0') {
        base_len++;
    }
	if(nbr == -2147483648)
	{
		write(1,"-2147483648",11);
		return (11);	
	}
    if (nbr < 0) 
	{
       count += write(1, "-", 1);
        nbr = -nbr;
    }

    if (nbr >= base_len) {
       count += ft_putnbr_base(nbr / base_len, base);
    }

    count += write(1, &base[nbr % base_len], 1);
	 return count;
}
int ft_putnbr_base_unsigned(unsigned int nbr, const char *base)
{
    int base_len = 0;
	int count;
	count = 0;
    while (base[base_len] != '\0') {
        base_len++;
    }
    if (nbr >= base_len) {
       count += ft_putnbr_base(nbr / base_len, base);
    }

    count += write(1, &base[nbr % base_len], 1);
	 return count;
}

int	ft_putnbr(unsigned int nb)
{
	int count;
	count = 0;
	if (nb >= 0 && nb < 10)
		count += ft_putchar(nb + '0');
	else
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return(count);
}
int ft_putstr(char const *str)
{
	int	i;
	int count;
	if(!str)
		return(write(1, "(null)",6));
	count = 0;
	i = 0;
	while(str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return count;
}

int	ft_convert_base16(unsigned long long int nb)
{
	char *base;
	base = "0123456789abcdef";
	int size;
	size = 0;
	
	if(nb >= 16)
	{
		size += ft_convert_base16(nb / 16);
	}	
	write(1, &base[nb % 16],1);
	size++;
	return (size);
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
				i += ft_putchar(va_arg(args,int));	
			else if (*str == 's')
				i += ft_putstr(va_arg(args,char *));
			else if(*str == 'd' || *str == 'i')
				i += ft_putnbr_base(va_arg(args,int),"0123456789");
			else if(*str == 'u')
				i += ft_putnbr(va_arg(args,int));
			else if(*str == 'x')
				i += ft_putnbr_base_unsigned((unsigned int)va_arg(args,int),"0123456789abcdef");
			else if (*str == 'X')
				i += ft_putnbr_base_unsigned((unsigned int)(va_arg(args,int)),"0123456789ABCDEF");
			else if (*str == '%')
				i += ft_putchar('%');
			else if(*str == 'p')
			{
				void *temp;
				temp = va_arg(args,void *);
				if(!temp)
					i += ft_putstr("(nil)");
				else{
					i += ft_putstr("0x");
					i += ft_convert_base16((unsigned long long int)temp);
				}
			}
		}
		 else
		 {
		 	i += write(1,&*str,1);
		 }
		 str++;
	}
	
	return i;
}
//   int	main()
//  {
// 	void *ptr;
// 	int v;
// 	int v1;

//  	v = ft_printf("%d",10);
// 	printf("%d",v);
//  }