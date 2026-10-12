/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 16:59:22 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/10/01 16:59:23 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
#include <limits.h>

//structs

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}	t_stack;

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

typedef struct s_op_count
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_op_count;

//stack

t_node	*new_node(int value, int index);
void	stack_add_front(t_stack *stack, t_node *node);
void	stack_add_back(t_stack *stack, t_node *node);
t_node	*stack_del_front(t_stack *stack);
void	free_list(t_node *head);
int		is_sorted(t_stack *stack);

//operations

void	pa(t_stack *a, t_stack *b, t_op_count *ope);
void	pb(t_stack *a, t_stack *b, t_op_count *ope);

void	sa(t_stack *a);
void	sa_print(t_stack *a, t_op_count *ope);
void	sb(t_stack *b);
void	sb_print(t_stack *b, t_op_count *ope);
void	ss(t_stack *a, t_stack *b, t_op_count *ope);

void	ra(t_stack *a);
void	ra_print(t_stack *a, t_op_count *ope);
void	rb(t_stack *b);
void	rb_print(t_stack *b, t_op_count *ope);
void	rr(t_stack *a, t_stack *b, t_op_count *ope);

void	rra(t_stack *a);
void	rra_print(t_stack *a, t_op_count *ope);
void	rrb(t_stack *b);
void	rrb_print(t_stack *b, t_op_count *ope);
void	rrr(t_stack *a, t_stack *b, t_op_count *ope);

//bench
double	disorder(t_stack *a);
void	print_strategy_info(t_strategy strat);
void	print_bench(double disorder, t_strategy strat, t_op_count *ope);

//algorithms

//medium
int		chunk_size(int n);
int		in_chunk(t_node *node, int chunk, int size);
int		count_in_chunk(t_stack *a, int chunk, int size);
int		find_t_pos(t_stack *b, int x_index);
int		find_max_pos(t_stack *b);
void	rotate_b_to_pos(t_stack *b, int pos, t_op_count *ope);
void	insert_in_b(t_stack *a, t_stack *b, t_op_count *ope);
void	return_to_a(t_stack *a, t_stack *b, t_op_count *ope);
void	chunk_sort(t_stack *a, t_stack *b, t_op_count *ope);

#endif
