/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:52:26 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/10 14:59:16 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include "../../42_Cursus_Crazy_Frog/libft/libft.h"

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
