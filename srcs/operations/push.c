/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:38:24 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/09/28 16:12:44 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pa(t_stack *a, t_stack *b, t_op_count *ope)
{
	t_node	*node;

	if (b->size == 0)
		return ;
	node = stack_del_front(b);
	stack_add_front(a, node);
	printf("pa\n");
	ope->pa++;
}

void	pb(t_stack *a, t_stack *b, t_op_count *ope)
{
	t_node	*node;

	if (a->size == 0)
		return ;
	node = stack_del_front(a);
	stack_add_front(b, node);
	printf("pb\n");
	ope->pb++;
}
