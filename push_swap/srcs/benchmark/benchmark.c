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

void	print_strategy_info(t_strategy strat)
{
	if (strat == STRAT_SIMPLE)
		ft_putstr_fd("[bench] Estrategia: Simple / O(n^2)\n", 2);
	else if (strat == STRAT_MEDIUM)
		ft_putstr_fd("[bench] Estrategia: Medium / O(n*sqrt(n))\n", 2);
	else if (strat == STRAT_COMPLEX)
		ft_putstr_fd("[bench] Estrategia: Complex / O(n log n)\n", 2);
	else
		ft_putstr_fd("[bench] Estrategia: Adaptive\n", 2);
}

static void	print_disorder(double disorder)
{
	int	pct;

	pct = (int)(disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] Disorder: ", 2);
	ft_putnbr_fd(pct / 100, 2);
	ft_putchar_fd('.', 2);
	if (pct % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(pct % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_count(char *name, int n)
{
	ft_putstr_fd(name, 2);
	ft_putnbr_fd(n, 2);
}

static void	print_ops(t_op_count *ope)
{
	ft_putstr_fd("[bench]", 2);
	print_count(" sa=", ope->sa);
	print_count(" sb=", ope->sb);
	print_count(" ss=", ope->ss);
	print_count(" pa=", ope->pa);
	print_count(" pb=", ope->pb);
	print_count(" ra=", ope->ra);
	print_count(" rb=", ope->rb);
	print_count(" rr=", ope->rr);
	print_count(" rra=", ope->rra);
	print_count(" rrb=", ope->rrb);
	print_count(" rrr=", ope->rrr);
	ft_putchar_fd('\n', 2);
}

void	print_bench(double disorder, t_strategy strat, t_op_count *ope)
{
	int	total;

	total = ope->sa + ope->sb + ope->ss + ope->pa + ope->pb
		+ ope->ra + ope->rb + ope->rr + ope->rra + ope->rrb + ope->rrr;
	print_disorder(disorder);
	print_strategy_info(strat);
	print_count("[bench] Operations total: ", total);
	ft_putchar_fd('\n', 2);
	print_ops(ope);
}
