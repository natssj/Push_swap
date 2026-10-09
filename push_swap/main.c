/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 13:16:28 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/10/07 13:16:29 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	init_data(t_data *d)
{
	d->a.top = NULL;
	d->a.bot = NULL;
	d->a.size = 0;
	d->b.top = NULL;
	d->b.bot = NULL;
	d->b.size = 0;
	d->cfg.strategy = STRAT_ADAPTIVE;
	d->cfg.bench = 0;
	d->disorder = 0.0;
	d->ope = (t_op_count){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}

static void	run_strategy(t_data *d)
{
	if (d->cfg.strategy == STRAT_ADAPTIVE)
		d->cfg.strategy = choose_strategy(d->disorder);
	if (d->cfg.strategy == STRAT_SIMPLE)
		insertion(&d->a, &d->b, &d->ope);
	else if (d->cfg.strategy == STRAT_MEDIUM)
		chunk_sort(&d->a, &d->b, &d->ope);
	else if (d->cfg.strategy == STRAT_COMPLEX)
		chunk_sort(&d->a, &d->b, &d->ope);
}

int	main(int argc, char **argv)
{
	t_data	d;
	int		start_numb;

	if (argc < 2)
		return (0);
	init_data(&d);
	start_numb = parsing_flags(argc, argv, &d.cfg);
	if (start_numb < 0)
		error_exit(&d.a, &d.b);
	if (start_numb == argc)
		return (0);
	if (!parsing_numbers(argc, argv, start_numb, &d.a))
		error_exit(&d.a, &d.b);
	assign_indexes(&d.a);
	d.disorder = compute_disorder(&d.a);
	run_strategy(&d);
	if (d.cfg.bench)
		print_bench(d.disorder, d.cfg.strategy, &d.ope);
	free_list(d.a.top);
	free_list(d.b.top);
	return (0);
}