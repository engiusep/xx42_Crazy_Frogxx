/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:37:24 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 13:48:02 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


void ft_lstadd_front(t_list **lst, t_list *new)
{
    if(new  && *lst)
    {
        new->next = *lst;
        new = *lst;
    }
}