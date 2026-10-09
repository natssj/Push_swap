/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 16:41:34 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/10/01 16:41:36 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	insert_in_b(t_stack *a, t_stack *b, t_op_count *ope)
{
	int	pos;

	if (b->size > 0)
	{
		pos = find_t_pos(b, a->top->index);
		rotate_b_to_pos(b, pos, ope);
	}
	pb(a, b, ope);
}

//deja el mayor de b arriba y lo devuelve todo a a
void	return_to_a(t_stack *a, t_stack *b, t_op_count *ope)
{
	rotate_b_to_pos(b, find_max_pos(b), ope);
	while (b->size > 0)
		pa(a, b, ope);
}

//cuantos nodos de a quedan por procesar en este chunk
int	count_in_chunk(t_stack *a, int chunk, int size)
{
	t_node	*cur;
	int		count;

	count = 0;
	cur = a->top;
	while (cur)
	{
		if (in_chunk(cur, chunk, size))
			count++;
		cur = cur->next;
	}
	return (count);
}

//funcion principal l.61 numero del ultimo chunk index -1 para saber el numero mas alto/size para saber a que chunk pertenece el numero mas alto
void	chunk_sort(t_stack *a, t_stack *b, t_op_count *ope)
{
	int	size;
	int	chunk;
	int	last;

	if (is_sorted(a))
		return ;
	size = chunk_size(a->size);
	last = (a->size - 1) / size;
	chunk = 0;
	while (chunk <= last)
	{
		while (count_in_chunk(a, chunk, size) > 0)
		{
			if (in_chunk(a->top, chunk, size))
				insert_in_b(a, b, ope);
			else
				ra_print(a, ope);
		}
		chunk++;
	}
	return_to_a(a, b, ope);
}
