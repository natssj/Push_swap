/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 16:14:16 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/09/28 16:14:19 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*first;

	if (a->size < 2)
		return ;
	first = a->top;
	a->top = a->top->next;
	a->top->prev = NULL;
	a->bot->next = first;
	first->prev = a->bot;
	first->next = NULL;
	a->bot = first;
}

void	ra_print(t_stack *a, t_op_count *ope)
{
	ra(a);
	ft_printf("ra\n");
	ope->ra++;
}

void	rb(t_stack *b)
{
	t_node	*first;

	if (b->size < 2)
		return ;
	first = b->top;
	b->top = b->top->next;
	b->top->prev = NULL;
	b->bot->next = first;
	first->prev = b->bot;
	first->next = NULL;
	b->bot = first;
}

void	rb_print(t_stack *b, t_op_count *ope)
{
	rb(b);
	ft_printf("rb\n");
	ope->rb++;
}

void	rr(t_stack *a, t_stack *b, t_op_count *ope)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
	ope->rr++;
}
