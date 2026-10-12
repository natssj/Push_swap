/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <nde-dieg@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:17:19 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/10/12 18:17:23 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

double	compute_disorder(t_stack *a)
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
