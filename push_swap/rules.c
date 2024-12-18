/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:19:20 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/11 12:19:42 by engiusep         ###   ########.fr       */
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
void	pa(t_stack *a, t_stack *b)
{
	if (b->top == -1)
		return ;
	a->arr[++a->top] = b->arr[b->top--];
	write(1, "pa\n", 3);
}
void	pb(t_stack *a, t_stack *b)
{
	if (a->top == -1)
		return ;
	b->arr[++b->top] = a->arr[a->top--];
	write(1, "pb\n", 3);
}
void	rra(t_stack *a)
{
	int	i;
	int	temp;

	i = 0;
	temp = a->arr[0];
	while (i <= a->top)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->top] = temp;
	write(1, "rra\n", 4);
}
void	rrb(t_stack *b)
{
	int	i;
	int	temp;

	i = 0;
	if (b->top < 0)
		return ;
	temp = b->arr[0];
	while (i <= b->top)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[b->top] = temp;
	write(1, "rrb\n", 4);
}
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

void	rrr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	i = 0;
	temp = a->arr[0];
	while (i <= a->top)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->top] = temp;
	temp = b->arr[0];
	i = 0;
	while (i <= b->top)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[b->top] = temp;
	write(1, "rrr\n", 4);
}
