/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <nde-dieg@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:22:52 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/10/12 18:22:58 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	insertion(t_stack *a, t_stack *b, t_op_count *ope)
{
	if (is_sorted(a))
		return ;
	while (a->size > 0)
		insert_in_b(a, b, ope);
	return_to_a(a, b, ope);
}
