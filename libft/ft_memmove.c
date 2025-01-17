/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:07:26 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/20 14:57:41 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptrdest;
	const unsigned char	*ptrsrc;

	ptrdest = dest;
	ptrsrc = src;
	if (ptrdest != ptrsrc)
	{
		if (ptrdest < ptrsrc)
		{
			while (n--)
				*ptrdest++ = (const char)*ptrsrc++;
		}
		else
		{
			while (n--)
				ptrdest[n] = ptrsrc[n];
		}
	}
	return (dest);
}
