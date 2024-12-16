/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:04:07 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/16 18:22:59 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display_stack(t_stack *a,t_stack *b)
{
	int i;
	int j;
	j = a->top;
	i = b->top;
	
	while(i >= 0 || j >= 0)
	{
		if(j >= 0)
			printf("%d",a->arr[j]);
		if(i >= 0)
			printf(" %d\n",b->arr[i]);
		else if(j >= 0 && i <= 0)
			printf("\n");
		
		i--;
		j--;
	}
	printf("_ _\n");
	printf("a b\n");
}

//recherche lindex du plus rend de la stack b
int find_big(t_stack *b)
{
	int i;
	int big;
	i = 0;
	big = 0;
	int index_big;
	
	while(i <= b->top)
		{
			if(big < b->arr[i])
			{
				big = b->arr[i];
				index_big = i;
			}
			i++;
		}
	return (index_big);
}
int find_min(t_stack *a)
{
	int i;
	int min;
	int index_min;
	i = 0;
	min = INT_MAX;
	
	while(i <= a->top)
		{
			if(min > a->arr[i])
			{
				min = a->arr[i];
				index_min = i;
			}
			i++;
		}
	return (index_min);
}

int close_big(int value, t_stack *a)
{
	int min_dif = INT_MAX;
	int i;
	int index_big;
	i = 0;
	while(i <= a->top)
	{
		if(value < a->arr[i] && a->arr[i] - value < min_dif)
		{
		 	min_dif = a->arr[i] - value;
			index_big = i;
		}
		i++;
	}
	if(min_dif == INT_MAX)
	{
		return(find_min(a));
	}
	return (index_big);
}
//cherche lindex du plus petit de la stack b;
int close_small(int value, t_stack *b)
{
	int min_dif = INT_MAX;
	int i;
	int index_small;
	i = 0;
	while(i <= b->top)
	{
		if(value > b->arr[i] && value - b->arr[i] < min_dif)
		{
		 	min_dif = value - b->arr[i];
			index_small = i;
		}
		i++;
	}
	
	if(min_dif == INT_MAX)
	{
		return(find_big(b));
	}
	return (index_small);
}

int cost_push(t_stack *a,t_stack *b)
{
	int value;
	int i;
	int cost_a;
	int cost_b;
	int index_big;
	int cost_final = INT_MAX;
	int index_final;
	index_final = 0;
	i = b->top;
	
	while(i >= 0)
	{
		if(i < b->top /2)
		{
			cost_b = i + 1;
		}
		else
			cost_b = b->top - i;
			
		index_big = close_big(b->arr[i],a);
		if(index_big < a->top / 2)
		{
			cost_a = index_big + 1;
		}
		else
			cost_a = a->top - index_big;
	
		if(cost_a + cost_b < cost_final)
		{
			cost_final = cost_a + cost_b;
			index_final = i;
		}
		//printf("cost_a : %d | cost_b : %d | cost : %d\n",cost_a, cost_b, cost_a + cost_b);
		i--;
	}
	return(index_final);
}
void	three_sort(t_stack *a)
{
	int big;
	int	i;
	i = a->top;
	big = find_big(a);
	big = a->arr[big];

	if(a->arr[a->top] == big)
		ra(a);
	else if(a->arr[a->top - 1] == big)
		rra(a);
	if(a->arr[a->top - 1] < a->arr[a->top])
		sa(a);
	
}
 int turksort(t_stack *a,t_stack *b)
{
	int index_big;
	int target_big;
	int index_final;
	int element;
	int target;
	int min;
	
	while(a->top > 2)
	{
		pb(a,b);
	}
	
	three_sort(a);
	
	while(b->top >= 0)
	{
		index_final = cost_push(a,b);
		index_big = close_big(b->arr[index_final],a);
		element = b->arr[index_final];
		target = a->arr[index_big];

		while(b->arr[b->top] != element)
		{
			
			rb(b);
			// if(index_big < b->top / 2)
			// 	rrb(b);
			// else
			// 	rb(b);
		}
		while(a->arr[a->top] != target)
		{
			ra(a);
			// if(index_big < a->top / 2)
			// 	rra(a);
			// else
			// 	ra(a);
		}
		pa(a,b);
		//printf("b->top = %d",b->top);
	}

	
	min = find_min(a);
	while(min >= 0)
	{
		rra(a);
		min--;
	}
	
	return (0);
	
}

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	
	a.top = -1;
	b.top = -1;
	

	while(argc > 1)
	{
		a.arr[++a.top] = atoi(argv[argc - 1]);
		argc--;
	}

	turksort(&a,&b);
}