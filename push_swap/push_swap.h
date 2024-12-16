/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:05:46 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/13 17:44:45 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#define stack_size 500
typedef struct s_stack
{
	int		arr[stack_size];
	int		top;
}t_stack;
void display_stack(t_stack *a,t_stack *b);
int turksort(t_stack *a,t_stack *b);
int find_big(t_stack *b);
int close_small(int value, t_stack *b);
int cost_push(t_stack *a,t_stack *b);
 int turksort(t_stack *a,t_stack *b);
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
#endif   