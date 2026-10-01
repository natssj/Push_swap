/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 16:26:28 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/09/28 16:26:29 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	total_pairs;

	if (!a || a->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / (double)total_pairs);
}

void	print_strategy_info(t_strategy strat)
{
	if (strat == STRAT_SIMPLE)
		fprintf(stderr, "[bench] Strategy: Simple / O(n^2)\n");
	else if (strat == STRAT_MEDIUM)
		fprintf(stderr, "[bench] Strategy: Medium / O(n*sqrt(n))\n");
	else if (strat == STRAT_COMPLEX)
		fprintf(stderr, "[bench] Strategy: Complex / O(n log n)\n");
	else if (strat == STRAT_ADAPTIVE)
		fprintf(stderr, "[bench] Strategy: Adaptive\n");
}

void	print_bench(double disorder, t_strategy strat, t_op_count *ope)
{
	int	total;

	total = ope->sa + ope->sb + ope->ss + ope->pa + ope->pb
		+ ope->ra + ope->rb + ope->rr + ope->rra + ope->rrb + ope->rrr;
	fprintf(stderr, "[bench] Disorder: %.2f%%\n", disorder * 100);
	print_strategy_info(strat);
	fprintf(stderr, "[bench] Opertations total: %d\n", total);
	fprintf(stderr,
		"[bench] sa=%d sb=%d ss=%d pa=%d pb=%d ra=%d rb=%d "
		"rr=%d rra=%d rrb=%d rrr=%d\n",
		ope->sa, ope->sb, ope->ss, ope->pa, ope->pb,
		ope->ra, ope->rb, ope->rr, ope->rra, ope->rrb, ope->rrr);
}
