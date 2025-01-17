/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:47:00 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/20 14:57:33 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;
	const char		*ptr_src;

	ptr_src = src;
	ptr = dest;
	if (((unsigned char *)dest == (void *)0)
		&& ((const char *)src == (void *)0))
		return (NULL);
	while (n--)
	{
		*ptr++ = (const char)*ptr_src++;
	}
	return (dest);
}
