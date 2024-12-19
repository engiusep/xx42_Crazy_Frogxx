/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:05:46 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/19 14:53:58 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	arr[1000];
	int	top;
}		t_stack;

typedef struct s_variable
{
	int	a_top;
	int	a_bot;
	int	b_top;
	int	b_bot;
}		t_variable;

// void	display_stack(t_stack *a, t_stack *b);
int		turksort(t_stack *a, t_stack *b);
void	rrr_or_rr(t_stack *a, t_stack *b, int index_final, int index_big);
void	rra_or_ra(t_stack *a, int target, int index_big);
void	rrb_or_rb(t_stack *b, int element, int index_final);
void	cost_logic(t_stack *a, t_stack *b, t_variable *var, int i);
void	rra_or_ra_final(t_stack *a);
int		cost_calc(t_variable *var);
int		cost_push(t_stack *a, t_stack *b);
int		find_big(t_stack *b);
int		find_min(t_stack *a);
int		close_big(int value, t_stack *a);
int		close_small(int value, t_stack *b);
int		cost_push(t_stack *a, t_stack *b);
int		turksort(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	rrb(t_stack *b);

#endif