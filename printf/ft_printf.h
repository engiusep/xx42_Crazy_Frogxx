/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:26:16 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/25 16:00:35 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_convert_base16(unsigned long long int nb);
int	ft_putstr(char const *str);
int	ft_putnbr_base(int nbr, const char *base);
int	ft_putchar(int c);
int	ft_putnbr(unsigned int nb);

#endif