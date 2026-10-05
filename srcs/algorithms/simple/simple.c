/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbecer <marbecer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:29:59 by marbecer          #+#    #+#             */
/*   Updated: 2026/10/05 19:10:35 by marbecer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recibe_numero.c"
//encontrar el valor minimo en b
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
//encontrar el valor maximo en b.
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
int	find_position(t_node value, t_stack *a, t_stack *b)
{
	t_node	*p;
	int pos; 
	
}




void	insertion(t_stack *a, t_stack *b)
{
	int min;
	int max;
	//incializar
	pb(a, b);
	pb(a, b);
	while (a != NULL)
	{
		min = get_max(b);
		max = get_max(b);
		//caso 1 nuevo min
		if (a -> top -> value < min)
			pb(a, b);
		//caso 2 nuevo max
		if (a -> top -> value > max)
			pb()
		//caso 3 intermedio
		if (entre min y max)
			find_position(a -> top, a, b)
	}
	while(b -> top != max)
		rb o rrb
	while(b != NULL)
		pa(a, b);
}
