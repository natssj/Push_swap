/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:38:14 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/10/07 15:38:16 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size <= 1)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	assign_indexes(t_stack *stack)
{
	t_node	*current;
	t_node	*scan;
	int		rank;

	if (!stack || stack->size == 0)
		return ;
	current = stack->top;
	while (current)
	{
		rank = 0;
		scan = stack->top;
		while (scan)
		{
			if (scan->value < current->value)
				rank++;
			scan = scan->next;
		}
		current->index = rank;
		current = current->next;
	}
}
