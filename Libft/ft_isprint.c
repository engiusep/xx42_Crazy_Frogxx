/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:29:18 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/04 16:29:19 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isprint(int  c)
{
    if(c >= 32 && c <= 126)
        return (1);
    return (0);
}