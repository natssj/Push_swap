/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbecer <marbecer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:29:59 by marbecer          #+#    #+#             */
/*   Updated: 2026/10/06 18:29:43 by marbecer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *b)
{
	t_node	*p;
	int	min;

	if(!b || !b -> top)
		return (0);
	min = b -> top -> value;
	p = b -> bot;
	while (p)
	{
		if (p->value < min)
			min = p -> value;
		p = p -> next;
	}
	return (min);
}
int	get_max(t_stack *b)
{
	t_node	*p;
	int	max;

	if(!b || !b -> top)
		return (0);
	max = b -> top -> value;
	p = b -> bot;
	while (p)
	{
		if (p->value < max)
			max = p -> value;
		p = p -> next;
	}
	return (max);
}
// va a mirar en que "hueco" va el numero
int	get_pos(t_stack *b, int value_a)
{
	t_node	*p;
	
	if (value_a > get_max(b) || value_a < get_min(b))
	return (get_max(b));
	p = b -> top;
	while(p && p -> next)
	{
		if (p -> value > value_a && p -> next -> value < value_a)
			return(p -> next ->value);
		p = p ->next;
	}
	return (get_max);
}



void	insertion(t_stack *a, t_stack *b, t_op_count *ope)
{
	int	pos;
	pb(a, b, ope);
	pb(a, b, ope);
	if (b -> top -> value < b -> top -> next -> value)
		sb_print(b, ope);
	while (a != NULL)
	{
		pos = get_pos(b, a -> top -> value);
		while(b ->top ->value != pos)
		{
			rotate_b_to_pos(b, pos, ope);
			pb(a, b, ope);
		}
	}
	while(b -> top != get_max(b))
		rotate_b_to_pos(b, pos, ope);
	while(b != NULL)
		pa(a, b, ope);
}
