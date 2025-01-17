/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:58:28 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/17 16:46:35 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	i = 0;
	temp = a->arr[0];
	while (i < a->top)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->top] = temp;
	temp = b->arr[0];
	i = 0;
	while (i < b->top)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[b->top] = temp;
	write(1, "rrr\n", 4);
}

void	rrb(t_stack *b)
{
	int	i;
	int	temp;

	i = 0;
	if (b->top < 0)
		return ;
	temp = b->arr[0];
	while (i < b->top)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[b->top] = temp;
	write(1, "rrb\n", 4);
}

void	rra(t_stack *a)
{
	int	i;
	int	temp;

	i = 0;
	if (a->top <= 0)
		return ;
	temp = a->arr[0];
	while (i < a->top)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->top] = temp;
	write(1, "rra\n", 4);
}
