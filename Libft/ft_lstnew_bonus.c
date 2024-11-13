/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:54:30 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/12 13:48:29 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


t_list *ft_lstnew(void *content)
{
    t_list *new;
    
    new = malloc(sizeof(t_list));
    new->content = content;
    new->next = NULL;
    return(new);
}

// int main()
// {
//     printf("%d",*ft_lstnew((void *)12));
// }