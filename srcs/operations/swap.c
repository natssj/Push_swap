/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <nde-dieg@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:16:15 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/10/12 18:16:19 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (a->size < 2)
		return ;
	first = a->top;
	second = a->top->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	a->top = second;
	if (a->size == 2)
		a->bot = first;
}

void	sa_print(t_stack *a, t_op_count *ope)
{
	sa(a);
	ft_printf("sa\n");
	ope->sa++;
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (b->size < 2)
		return ;
	first = b->top;
	second = b->top->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	b->top = second;
	if (b->size == 2)
		b->bot = first;
}

void	sb_print(t_stack *b, t_op_count *ope)
{
	sb(b);
	ft_printf("sb\n");
	ope->sb++;
}

void	ss(t_stack *a, t_stack *b, t_op_count *ope)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
	ope->ss++;
}
