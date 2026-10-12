/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 16:15:02 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/09/28 16:15:03 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*last;

	if (a->size < 2)
		return ;
	last = a->bot;
	a->bot = a->bot->prev;
	a->bot->next = NULL;
	last->next = a->top;
	a->top->prev = last;
	last->prev = NULL;
	a->top = last;
}

void	rra_print(t_stack *a, t_op_count *ope)
{
	rra(a);
	printf("rra\n");
	ope->rra++;
}

void	rrb(t_stack *b)
{
	t_node	*last;

	if (b->size < 2)
		return ;
	last = b->bot;
	b->bot = b->bot->prev;
	b->bot->next = NULL;
	last->next = b->top;
	b->top->prev = last;
	last->prev = NULL;
	b->top = last;
}

void	rrb_print(t_stack *b, t_op_count *ope)
{
	rrb(b);
	printf("rrb\n");
	ope->rrb++;
}

void	rrr(t_stack *a, t_stack *b, t_op_count *ope)
{
	rra(a);
	rrb(b);
	printf("rrr\n");
	ope->rrr++;
}
