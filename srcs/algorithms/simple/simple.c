/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbecer <marbecer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:29:59 by marbecer          #+#    #+#             */
/*   Updated: 2026/10/01 17:20:38 by marbecer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recibe_numero.c"
//encontrar el valor minimo en b
int	min(t_stack *b)
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
//encontrar el valor maximo en b.
int	max(t_stack *b)
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
int	find_position(t_node value, t_stack *a, t_stack *b)
{
	t_node	*p;
	int pos; 
	
}

aaaaaaaaaaaaaaaaa no se cmo hacerloooooooooo pero era buscar entre min y max donde va el numero de a
para pasarlo a b de forma ordenada, el b es el que va haciendo rb y rrb, 
y luego todo push a para pasarlo a a, por lo que el stack b queda de mayor a menor, 
el a de menor a mayor. 
aaaaaaaaaaaaaaaAAA


void	insertion(t_stack *a, t_stack *b)
{
	void	*tmp;

}