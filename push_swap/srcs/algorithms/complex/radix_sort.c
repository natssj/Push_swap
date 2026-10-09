/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 20:12:08 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/10/09 20:12:09 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	max_bits(int size)
{
	int	bits;
	int	max;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_pass(t_stack *a, t_stack *b, t_op_count *ope, int bit)
{
	int	n;
	int	i;

	n = a->size;
	i = 0;
	while (i < n)
	{
		if (((a->top->index >> bit) & 1) == 0)
			pb(a, b, ope);
		else
			ra_print(a, ope);
		i++;
	}
	while (b->size > 0)
		pa(a, b, ope);
}

void	radix_sort(t_stack *a, t_stack *b, t_op_count *ope)
{
	int	bits;
	int	bit;

	if (is_sorted(a))
		return ;
	bits = max_bits(a->size);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(a, b, ope, bit);
		bit++;
	}
}
