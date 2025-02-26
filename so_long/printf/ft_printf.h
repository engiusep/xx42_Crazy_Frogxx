/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:45:42 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/29 16:06:03 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putnbr(unsigned int nb);
int	ft_putnbr_base(int nbr, const char *base);
int	ft_putnbr_base_unsigned(unsigned int nbr, const char *base);
int	ft_printf(const char *str, ...);

#endif