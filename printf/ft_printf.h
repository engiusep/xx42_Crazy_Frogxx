/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:26:16 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/18 18:29:19 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "ft_printf.h"
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_convert_base16(unsigned long long int nb);
int ft_putstr(char const *str);
int ft_putnbr_base(int nbr, const char *base);
int	ft_putchar(int c);
int	ft_putnbr(unsigned int nb);

#endif