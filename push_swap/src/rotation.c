/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:50:16 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/17 17:18:48 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_stack *a, t_stack *b)
{
	sa(a);
	free(a->arr);
	free(b->arr);
	exit(1);
}

void	rrr_or_rr(t_stack *a, t_stack *b, int index_final, int index_big)
{
	int	element;
	int	target;

	element = b->arr[index_final];
	target = a->arr[index_big];
	while (b->arr[b->top] != element && a->arr[a->top] != target)
	{
		if (index_final < b->top / 2 && index_big < a->top / 2)
			rrr(a, b);
		else if (index_final >= b->top / 2 && index_big >= a->top / 2)
			rr(a, b);
		else
			break ;
	}
}

void	rra_or_ra(t_stack *a, int target, int index_big)
{
	while (a->arr[a->top] != target)
	{
		if (index_big < a->top / 2)
			rra(a);
		else
			ra(a);
	}
}

void	rrb_or_rb(t_stack *b, int element, int index_final)
{
	while (b->arr[b->top] != element)
	{
		if (index_final < b->top / 2)
			rrb(b);
		else
			rb(b);
	}
}

void	rra_or_ra_final(t_stack *a)
{
	int	min;
	int	value;

	min = 0;
	min = find_min(a);
	value = a->arr[min];
	if (min < a->top / 2)
	{
		while (value != a->arr[a->top])
		{
			rra(a);
			min--;
		}
	}
	else
	{
		while (value != a->arr[a->top])
		{
			ra(a);
			min++;
		}
	}
}
