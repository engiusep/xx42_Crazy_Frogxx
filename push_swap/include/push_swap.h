/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:05:46 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/17 17:20:31 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*arr;
	int		top;
}			t_stack;

typedef struct s_variable
{
	int		a_top;
	int		a_bot;
	int		b_top;
	int		b_bot;
}			t_variable;

int			turksort(t_stack *a, t_stack *b);
void		rrr_or_rr(t_stack *a, t_stack *b, int index_final, int index_big);
void		rra_or_ra(t_stack *a, int target, int index_big);
void		rrb_or_rb(t_stack *b, int element, int index_final);
void		cost_logic(t_stack *a, t_stack *b, t_variable *var, int i);
void		rra_or_ra_final(t_stack *a);
int			cost_calc(t_variable *var);
int			cost_push(t_stack *a, t_stack *b);
int			find_big(t_stack *b);
int			find_min(t_stack *a);
int			close_big(int value, t_stack *a);
int			close_small(int value, t_stack *b);
int			cost_push(t_stack *a, t_stack *b);
int			turksort(t_stack *a, t_stack *b);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rra(t_stack *a);
void		rr(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		rrb(t_stack *b);
int			check_stack(char **str);
long int	ft_atol(char *str);
int			sorted(t_stack *stack, t_stack *b);
int			check_double(char **str);
int			check_stack_1(char **splt, int i);
int			ft_strlen_split(char **split);
void		free_all2(char **split, int j);
void		create_stack_split(char **argv, t_stack *a, t_stack *b);
void		put_in_stack_argv(char **argv, t_stack *a, int argc, t_stack *b);
void		create_stack_argv(char **argv, t_stack *a, t_stack *b, int argc);
int			check_empty_string(char **argv, int argc);
void		swap_a(t_stack *a, t_stack *b);
int			free_stack(t_stack *a, t_stack *b);
int			free_error_malloc(t_stack *a, char **splt, int i);
#endif