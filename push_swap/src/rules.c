/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:19:20 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/17 17:18:46 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->top < 0)
		return ;
	i = b->top;
	temp = b->arr[b->top];
	while (i >= 1)
	{
		b->arr[i] = b->arr[i - 1];
		i--;
	}
	b->arr[0] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	i = 0;
	i = a->top;
	temp = a->arr[a->top];
	while (i >= 1)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = temp;
	i = b->top;
	temp = b->arr[b->top];
	while (i >= 1)
	{
		b->arr[i] = b->arr[i - 1];
		i--;
	}
	b->arr[0] = temp;
	write(1, "rr\n", 3);
}

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	i = a->top;
	temp = a->arr[a->top];
	while (i >= 1)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = temp;
	write(1, "ra\n", 3);
}
