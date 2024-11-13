/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:49:52 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 13:48:00 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


t_list *ft_lstlast(t_list *lst)
{
    t_list *move;
    move = lst;
    while(move->next != NULL)
        move = move->next;
    return(move);
}
