/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recibe_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:07:44 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/09/22 15:39:55 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*new_node(int value, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_add_front(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	node->prev = NULL;
	if (stack->top)
		stack->top->prev = node;
	stack->top = node;
	if (stack->size == 0)
		stack->bot = node;
	stack->size++;
}

t_node	*stack_del_front(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	stack->top = stack->top->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bot = NULL;
	stack->size--;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_add_back(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = NULL;
	node->prev = stack->bot;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bot = node;
	}
	else
	{
		stack->bot->next = node;
		stack->bot = node;
	}
	stack->size++;
}

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size <= 1)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	assign_indexes(t_stack *stack)
{
	t_node	*current;
	t_node	*scan;
	int		rank;

	if (!stack || stack->size == 0)
		return ;
	current = stack->top;
	while (current)
	{
		rank = 0;
		scan = stack->top;
		while (scan)
		{
			if (scan->value < current->value)
				rank++;
			scan = scan->next;
		}
		current->index = rank;
		current = current->next;
	}
}

// int	main(int argc, char **argv)
// {
// 	t_stack	a;
// 	t_stack	b;
// 	t_node	*tmp;
// 	int		i;

// 	a.top = NULL;
// 	a.bot = NULL;
// 	a.size = 0;
// 	b.top = NULL;
// 	b.bot = NULL;
// 	b.size = 0;
// 	i = 1;
// 	while (i < argc)
// 	{
// 		tmp = new_node(atoi(argv[i]), 0);
// 		stack_add_back(&a, tmp);
// 		i++;
// 	}
// 	tmp = a.top;
// 	printf("Stack A (size=%d):\n", a.size);
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->value);
// 		tmp = tmp->next;
// 	}
// 	tmp = b.top;
// 	printf("Stack B (size=%d):\n", b.size);
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->value);
// 		tmp = tmp->next;
// 	}
// 	free_list(a.top);
// 	free_list(b.top);
// 	return (0);
}
