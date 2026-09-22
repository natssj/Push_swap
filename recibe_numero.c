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

#include <stdlib.h>
//---------------------------Creación de listas
typedef struct s_node
{
	int				value;
	int				index; //posición que quedaría al ordenaarlo entero
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size; //contador de values
}	t_stack;

t_node	*new_node(int value, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL; //crea el nodo sin enlazarse a ninguno
	return (node);
}

void	stack_add_front(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top; //nodo nuevo apunta al principio
	stack->top = node;
	if (stack->size == 0) //si el stack estaba vacio top y bot son el mismo
		stack->bot = node;
	stack->size++;
}

void	stack_add_back(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = NULL;
	if (stack->size == 0) //si el stack estaba vacio top y bot son el mismo
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
//---------------------------Consultas

int	is_sorted(t_stack *stack) //valida que el stack esté ordenado
{
	t_node	*current;

	if (!stack || stack->size <= 1) //Stack vacío o 1 elemento => ordenado
		return (1);
	current = stack->top;
	while (current->next) //mientras haya un "siguiente", es que hay más, por eso entra al bucle
	{
		if (current->value > current->next->value) //si el valor actual es mayor al siguiente, hay desorden
			return (0);
		current = current->next;
	}
	return (1);
}
t_node	*stack_pop_front(t_stack *stack) //quita el primer nodo
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	stack->top = stack->top->next; //el que era el segundo pasa a ser top
	if (!stack->top)
		stack->bot = NULL; //si al quitar top se vacia, bot es NULL pq no apunta a nada
	stack->size--;
	node->next = NULL;
	return (node);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_node	*tmp;
	int		i;

	a.top = NULL;
	a.bot = NULL;
	a.size = 0;
	b.top = NULL;
	b.bot = NULL;
	b.size = 0;
	i = 1;
	while (i < argc)
	{
		tmp = new_node(atoi(argv[i]), 0);
		stack_add_back(&a, tmp);
		i++;
	}
	tmp = a.top;
	printf("Stack A (size=%d):\n", a.size);
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	tmp = b.top;
	printf("Stack B (size=%d):\n", b.size);
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	free_list(a.top);
	free_list(b.top);
	return (0);
}
