/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbecer <marbecer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:29:59 by marbecer          #+#    #+#             */
/*   Updated: 2026/10/06 17:42:03 by marbecer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recibe_numero.c"

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

int	rt(t_stack *b, int value_)
{
	int	pos;

	pos = get_pos(b, value_);
	if (pos <= b-> size / 2 )
	{
		while(b -> top -> value != value_)
			rb(b);
	}
	else
	{
		while (b ->top->value != value_)
			rrb(b);
	}
}


void	insertion(t_stack *a, t_stack *b)
{
	int	pos;
	pb(a, b);
	pb(a, b);
	if (b -> top -> value < b -> top -> next -> value)
		sb(b);
	while (a != NULL)
	{
		pos = get_pos(b, a -> top -> value);
		while(b ->top ->value != pos)
		{
			count()
		}
	}
	while(b -> top != get_max(b))
		rb(b);
	while(b != NULL)
		pa(a, b);
}
