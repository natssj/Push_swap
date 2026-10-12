/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 19:05:12 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/10/05 19:05:15 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	chunk_size(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	i--;
	if (i < 1)
		return (1);
	return (i);
}

int	in_chunk(t_node *node, int chunk, int size)
{
	return (node->index / size == chunk);
}

int	find_t_pos(t_stack *b, int x_index)
{
	t_node	*cur;
	int		pos;
	int		best_pos;
	int		best_index;

	best_pos = -1;
	best_index = -1;
	cur = b->top;
	pos = 0;
	while (cur)
	{
		if (cur->index < x_index && cur->index > best_index)
		{
			best_index = cur->index;
			best_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	if (best_pos != -1)
		return (best_pos);
	return (find_max_pos(b));
}

int	find_max_pos(t_stack *b)
{
	t_node	*cur;
	int		pos;
	int		max_pos;
	int		max_index;

	max_pos = 0;
	max_index = -1;
	cur = b->top;
	pos = 0;
	while (cur)
	{
		if (cur->index > max_index)
		{
			max_index = cur->index;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

void	rotate_b_to_pos(t_stack *b, int pos, t_op_count *ope)
{
	if (pos <= b->size / 2)
	{
		while (pos > 0)
		{
			rb_print(b, ope);
			pos--;
		}
	}
	else
	{
		pos = b->size - pos;
		while (pos > 0)
		{
			rrb_print(b, ope);
			pos--;
		}
	}
}
