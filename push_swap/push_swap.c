/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:04:07 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/16 18:42:50 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int ft_strlen_split(char **split)
{
	int i;
	i = 0;
	while(split[i])
		i++;
	return (i);
	
}
void    free_all2(char **split, int j)
{
        int     i;
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
	char **str_split;
	int j = 0;
	a.top = -1;
	b.top = -1;
	argc = argc - 1;

	if(argc == 1)
	{
		str_split = ft_split(argv[1], ' ');
		
		if(check_stack_1(str_split, 1) == 1)
		{
			exit(EXIT_FAILURE);
		}
		j = ft_strlen_split(str_split);
		a.arr = malloc(j * sizeof(int));
		if(!a.arr)
		{
			free_all2(str_split,j);
			return(0);
		}
		b.arr = malloc(j * sizeof(int));
		if(!b.arr)
		{
			free_all2(str_split,j);
			return (1);
		}
		j = j - 1;	
		while(j >= 0)
		{
			a.arr[++a.top] = ft_atol(str_split[j]);
			if(ft_atol(str_split[j]) > INT_MAX || ft_atol(str_split[j]) < INT_MIN)
			{
				write(2,"Error\n",7);
				free(a.arr);
				free(b.arr);
				free_all2(str_split, 0);
				return(1);
			}
			j--;
		}
		free_all2(str_split,ft_strlen_split(str_split));
	}
	else
	{
		if(check_stack_1(argv + 1, 0) == 1)
			exit(0);
		a.arr = malloc(argc * sizeof(int));
		if(!a.arr)
			return (1);
		b.arr = malloc(argc * sizeof(int));
		if(!b.arr)
		{
			free(a.arr);
			return (1);
		}
		while (argc >= 1)
		{
			a.arr[++a.top] = ft_atol(argv[argc]);
			if(ft_atol(argv[argc]) > INT_MAX || ft_atol(argv[argc]) < INT_MIN)
			{
				free(a.arr);
				free(b.arr);
				return(-1);
			}
			argc--;
		}
	}
	if(sorted(a) == 1)
	{
		free(a.arr);
		free(b.arr);
		return (0);
	}
	if(a.top == 1)
	{
		sa(&a);
		free(a.arr);
		free(b.arr);
		return (0);
	}
	push_in_b(&a, &b);
	three_sort(&a);
	turksort(&a, &b);
	free(a.arr);
	free(b.arr);
}
