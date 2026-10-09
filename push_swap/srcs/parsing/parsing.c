/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:41:18 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/10/08 14:19:38 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing_flags(int argc, char **argv, t_config *cfg)
{
	int	i;
	int	numflags;

	i = 1;
	numflags = 0;
	while (i < argc)
	{
		if (get_strategy(argv[i], cfg))
			numflags++;
		else if (str_equal(argv[i], "--bench"))
			cfg->bench = 1;
		else
			break ;
		i++;
	}
	if (numflags > 1)
		return (-1);
	return (i);
}

static int	fill_values(int argc, char **argv, int start, long *values)
{
	int	i;

	i = start;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		values[i - start] = str_to_long(argv[i]);
		if (!fits_in_int(values[i - start]))
			return (0);
		i++;
	}
	return (1);
}

static int	build_stack(long *values, int count, t_stack *a)
{
	int		i;
	t_node	*node;

	i = 0;
	while (i < count)
	{
		node = new_node((int)values[i], 0);
		if (!node)
			return (0);
		stack_add_back(a, node);
		i++;
	}
	return (1);
}

int	parsing_numbers(int argc, char **argv, int start, t_stack *a)
{
	long	*values;
	int		count;
	int		ok;

	count = argc - start;
	values = malloc(sizeof(long) * count);
	if (!values)
		return (0);
	ok = fill_values(argc, argv, start, values)
		&& !has_duplicate(values, count)
		&& build_stack(values, count, a);
	free(values);
	return (ok);
}
