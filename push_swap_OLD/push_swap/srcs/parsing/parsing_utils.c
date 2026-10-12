/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:53:13 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/10/07 15:53:14 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_equal(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] != '\0' && a[i] == b[i])
		i++;
	return (a[i] == b[i]);
}

int	get_strategy(char *arg, t_config *cfg)
{
	if (str_equal(arg, "--simple"))
		cfg->strategy = STRAT_SIMPLE;
	else if (str_equal(arg, "--medium"))
		cfg->strategy = STRAT_MEDIUM;
	else if (str_equal(arg, "--complex"))
		cfg->strategy = STRAT_COMPLEX;
	else if (str_equal(arg, "--adaptive"))
		cfg->strategy = STRAT_ADAPTIVE;
	else
		return (0);
	return (1);
}

void	error_exit(t_stack *a, t_stack *b)
{
	free_list(a->top);
	free_list(b->top);
	write(2, "Error\n", 6);
	exit(1);
}
