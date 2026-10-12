/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <nde-dieg@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:13:27 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/10/12 18:13:31 by nde-dieg         ###   ########.fr       */
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
	ft_printf("pa\n");
	ope->pa++;
}

void	pb(t_stack *a, t_stack *b, t_op_count *ope)
{
	t_node	*node;

	if (a->size == 0)
		return ;
	node = stack_del_front(a);
	stack_add_front(b, node);
	ft_printf("pb\n");
	ope->pb++;
}
