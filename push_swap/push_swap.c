/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:04:07 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/18 17:18:20 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	display_stack(t_stack *a, t_stack *b)
// {
// 	int	i;
// 	int	j;

// 	j = a->top;
// 	i = b->top;
// 	while (i >= 0 || j >= 0)
// 	{
// 		if (j >= 0)
// 			printf("%d", a->arr[j]);
// 		if (i >= 0)
// 			printf(" %d\n", b->arr[i]);
// 		else if (j >= 0 && i <= 0)
// 			printf("\n");
// 		i--;
// 		j--;
// 	}
// 	printf("_ _\n");
// 	printf("a b\n");
// }



// recherche lindex du plus rend de la stack b
int	find_big(t_stack *b)
{
	int	i;
	int	big;
	int	index_big;

	i = 0;
	big = 0;
	while (i <= b->top)
	{
		if (big < b->arr[i])
		{
			big = b->arr[i];
			index_big = i;
		}
		i++;
	}
	return (index_big);
}
int	find_min(t_stack *a)
{
	int	i;
	int	min;
	int	index_min;

	i = 0;
	min = INT_MAX;
	while (i <= a->top)
	{
		if (min > a->arr[i])
		{
			min = a->arr[i];
			index_min = i;
		}
		i++;
	}
	return (index_min);
}

int	close_big(int value, t_stack *a)
{
	int	min_dif;
	int	i;
	int	index_big;

	min_dif = INT_MAX;
	i = 0;
	while (i <= a->top)
	{
		if (value < a->arr[i] && a->arr[i] - value < min_dif)
		{
			min_dif = a->arr[i] - value;
			index_big = i;
		}
		i++;
	}
	if (min_dif == INT_MAX)
	{
		return (find_min(a));
	}
	return (index_big);
}

int	close_small(int value, t_stack *b)
{
	int	min_dif;
	int	i;
	int	index_small;

	min_dif = INT_MAX;
	i = 0;
	while (i <= b->top)
	{
		if (value > b->arr[i] && value - b->arr[i] < min_dif)
		{
			min_dif = value - b->arr[i];
			index_small = i;
		}
		i++;
	}
	if (min_dif == INT_MAX)
	{
		return (find_big(b));
	}
	return (index_small);
}

int	cost_push(t_stack *a, t_stack *b)
{
	t_variable var;
	int	i;
	int	index_big;
	int	cost_final;
	int	index_final;
	int	min_cost;
	
	min_cost = INT_MAX;
	index_final = 0;
	i = b->top;
	while (i >= 0)
	{
		cost_final = 0;
		var.a_top = 0;
		var.b_top = 0;
		var.a_bot = 0;
		var.b_bot = 0;
		if (i < b->top / 2)
			var.b_bot = i + 1;
		else
			var.b_top = b->top - i;
		index_big = close_big(b->arr[i], a);
		if (index_big < a->top / 2)
			var.a_bot = index_big + 1;
		else
			var.a_top = a->top - index_big;
		if (var.a_top > var.b_top)
			cost_final += var.a_top;
		else if (var.a_top < var.b_top)
			cost_final += var.b_top;
		else
			cost_final += var.a_top;
		if (var.a_bot > var.b_bot)
			cost_final += var.a_bot;
		else if (var.a_bot < var.b_bot)
			cost_final += var.b_bot;
		else
			cost_final += var.a_bot;
		if (cost_final < min_cost)
		{
			min_cost = cost_final;
			index_final = i;
		}
		i--;
	}
	return (index_final);
}
void	three_sort(t_stack *a)
{
	int	big;
	int	ind_big;
	int	i;

	i = a->top;
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
	int	min;
	min = 0;
	while (b->top >= 0)
	{
		index_final = cost_push(a, b);
		index_big = close_big(b->arr[index_final], a);
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
		while (a->arr[a->top] != target)
		{
			if (index_big < a->top / 2)
				rra(a);
			else
				ra(a);
		}
		while (b->arr[b->top] != element)
		{
			if (index_final < b->top / 2)
				rrb(b);
			else
				rb(b);
		}
		pa(a, b);
	}
	while (min >= 0)
	{
		min = find_min(a);
		if(min > a->top / 2)
			ra(a);
		else
			rra(a);
		min--;
	}
	return (0);
}
void	push_in_b(t_stack *a, t_stack *b)
{
	int median;
	int new_min;
	int i;
	i = 0;

	// median = a->arr[find_min(a)];
	// while(i < (a->top / 2 - 1))
	// {
	// 	new_min = a->arr[close_big(median,a)];
	// 	median = new_min;
	// 	i++;
	// } 
	while (a->top > 2)
	{
		pb(a, b);
		if(b->arr[b->top] < median)
			rb(b);
	}
}
int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	a.top = -1;
	b.top = -1;
	argc = argc - 1;

	while (argc >= 1)
	{
		a.arr[++a.top] = atoi(argv[argc]);
		argc--;
	}
	push_in_b(&a, &b);
	three_sort(&a);
	turksort(&a, &b);
}