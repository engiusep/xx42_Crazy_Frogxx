/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:04:07 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/17 17:20:53 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	three_sort(t_stack *a)
{
	int	big;
	int	ind_big;

	ind_big = find_big(a);
	big = a->arr[ind_big];
	if (a->arr[a->top] == big)
		ra(a);
	else if (a->arr[a->top - 1] == big)
		rra(a);
	if (a->arr[a->top - 1] < a->arr[a->top])
		sa(a);
}

int	turksort(t_stack *a, t_stack *b)
{
	int	index_big;
	int	index_final;
	int	element;
	int	target;

	while (b->top >= 0)
	{
		index_final = cost_push(a, b);
		index_big = close_big(b->arr[index_final], a);
		element = b->arr[index_final];
		target = a->arr[index_big];
		rrr_or_rr(a, b, index_final, index_big);
		rra_or_ra(a, target, index_big);
		rrb_or_rb(b, element, index_final);
		pa(a, b);
	}
	rra_or_ra_final(a);
	return (0);
}

void	push_in_b(t_stack *a, t_stack *b)
{
	int	median;
	int	new_min;
	int	i;

	i = 0;
	median = a->arr[find_min(a)];
	while (i < (a->top / 2 - 1))
	{
		new_min = a->arr[close_big(median, a)];
		median = new_min;
		i++;
	}
	while (a->top > 2)
	{
		pb(a, b);
		if (b->arr[b->top] < median)
			rb(b);
	}
}

void	free_all2(char **split, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.top = -1;
	b.top = -1;
	argc = argc - 1;
	check_empty_string(argv, argc + 1);
	if (argc == 1)
		create_stack_split(argv, &a, &b);
	else
		create_stack_argv(argv, &a, &b, argc);
	sorted(&a, &b);
	if (a.top == 1)
		swap_a(&a, &b);
	push_in_b(&a, &b);
	three_sort(&a);
	turksort(&a, &b);
	free_stack(&a, &b);
}
