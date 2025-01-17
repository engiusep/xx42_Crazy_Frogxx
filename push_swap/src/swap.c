/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:56:29 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/19 14:59:46 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	temp = a->arr[a->top];
	a->arr[a->top] = a->arr[a->top - 1];
	a->arr[a->top - 1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	temp;

	temp = b->arr[b->top];
	b->arr[b->top] = b->arr[b->top - 1];
	b->arr[b->top - 1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	temp = 0;
	temp = a->arr[a->top];
	a->arr[a->top] = a->arr[a->top - 1];
	a->arr[a->top - 1] = temp;
	temp = 0;
	temp = b->arr[b->top];
	b->arr[b->top] = b->arr[b->top - 1];
	b->arr[b->top - 1] = temp;
	write(1, "ss\n", 3);
}
