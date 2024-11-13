/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:43:55 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 13:47:54 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"


int ft_lstsize(t_list *lst)
{
    t_list *count;
    int i;
    i = 0;
    while(count->next != NULL)
    {
        count = count->next;
        i++;
    }
    return (i);
}
