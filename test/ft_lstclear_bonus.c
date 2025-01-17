/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:04:20 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/15 13:59:33 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*move;
	t_list	*temp;

	if (!lst || !del)
		return ;
	move = *lst;
	while (move != NULL)
	{
		temp = move->next;
		ft_lstdelone(move, del);
		move = temp;
	}
	*lst = NULL;
}
