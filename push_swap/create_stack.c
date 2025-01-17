/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:40:29 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/17 16:00:34 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_in_stack_argv(char **argv, t_stack *a, int argc, t_stack *b)
{
	a->arr[++a->top] = ft_atol(argv[argc]);
	if (ft_atol(argv[argc]) > INT_MAX || ft_atol(argv[argc]) < INT_MIN)
	{
		write(2, "Error\n", 6);
		free(a->arr);
		free(b->arr);
		exit(1);
	}
	return (0);
}
int	put_in_stack(char **str_split, t_stack *a, int j, t_stack *b)
{
	a->arr[++a->top] = ft_atol(str_split[j]);
	if (ft_atol(str_split[j]) > INT_MAX || ft_atol(str_split[j]) < INT_MIN)
	{
		write(2, "Error\n", 6);
		free(a->arr);
		free(b->arr);
		free_all2(str_split, ft_strlen_split(str_split));
		exit(1);
	}
	return (0);
}
int	create_stack_argv(char **argv, t_stack *a, t_stack *b, int argc)
{
	if (check_stack_1(argv + 1, 0) == 1)
		exit(0);
	a->arr = malloc(argc * sizeof(int));
	if (!a->arr)
		return (1);
	b->arr = malloc(argc * sizeof(int));
	if (!b->arr)
	{
		free(a->arr);
		return (1);
	}
	while (argc >= 1)
	{
		if (put_in_stack_argv(argv, a, argc, b) == 1)
			return (1);
		argc--;
	}
	return (0);
}
void	allo_a_b(t_stack *a, t_stack *b, int j, char **str_split)
{

	a->arr = malloc(j * sizeof(int));
	if (!a->arr)
		free_error_malloc(a,str_split,1);
	b->arr = malloc(j * sizeof(int));
	if (!b->arr)
		free_error_malloc(a,str_split,0);
	return;
}
int	create_stack_split(char **argv, t_stack *a, t_stack *b)
{
	int		j;
	char	**str_split;

	j = 0;
	a->top = -1;
	b->top = -1;
	str_split = ft_split(argv[1], ' ');
	if (!str_split)
		exit(1);
	if (check_stack_1(str_split, 1) == 1)
		return (1);
	j = ft_strlen_split(str_split);
	allo_a_b(a,b,j,str_split);
	j = j - 1;
	while (j >= 0)
	{
		if (put_in_stack(str_split, a, j, b) == 1)
			return (1);
		j--;
	}
	free_all2(str_split, ft_strlen_split(str_split));
	return (0);
}
