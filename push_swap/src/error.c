/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:17:15 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/17 16:51:51 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	free_error_malloc(t_stack *a, char **str_split, int i)
{
	if (i == 1)
		free_all2(str_split, ft_strlen_split(str_split));
	else
	{
		free_all2(str_split, ft_strlen_split(str_split));
		free(a->arr);
	}
	exit(1);
}

int	free_stack(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
	exit(1);
}

int	check_empty_string(char **argv, int argc)
{
	int	i;

	i = 0;
	if (argc == 1)
		exit(1);
	while (argv[1][i] == ' ')
	{
		if (argv[1][i + 1] == '\0')
		{
			write(2, "Error\n", 7);
			exit(1);
		}
		i++;
	}
	return (0);
}

int	check_stack_1(char **splt, int i)
{
	if (check_double(splt, i) == -1)
	{
		write(2, "Error\n", 7);
		if (i == 1)
			free_all2(splt, ft_strlen_split(splt));
		exit(EXIT_FAILURE);
	}
	if (check_stack(splt) == -1)
	{
		if (i == 1)
			free_all2(splt, ft_strlen_split(splt));
		write(2, "Error\n", 7);
		return (1);
	}
	return (0);
}
