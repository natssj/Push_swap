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
#include <stdio.h>
//---------------------------Creación de listas
typedef struct s_node
{
	int				value;
	int				index; //posición que quedaría al ordenaarlo entero
	struct s_node	*next;
	struct s_node	*prev; //nodo anterior
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
		stack->top->prev = node; //el nodo que era el primero apunta al nuevo primero
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

//----------------------------- Operaciones

//pa -> quita el primer nodo de B y lo coloca como primero de A
void	pa(t_stack *a, t_stack *b)  //del front (B) + add_front (A)
{
	t_node	*node;

	if (b->size == 0)
		return ;
	node = stack_del_front(b);
	stack_add_front(a, node);
	printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (a->size == 0)
		return ;
	node = stack_del_front(a);
	stack_add_front(b, node);
	printf("pb\n");
}

//sa -> intercambia los dos primeros elementos del stack

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (a->size < 2)
		return ;
	first = a->top; 		//guarda la referencia
	second = a->top->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	if (first->next)//Si hay un tercer nodo
		first->next->prev = first; //Ese tercero ahora tiene a first como prev
	a->top = second; //se actualiza el top
	if (a->size == 2)
		a->bot = first; //en este caso específico se actualiza bot también
}

void	sa_print(t_stack *a)
{
	sa(a);
	printf("sa\n");
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (b->size < 2)
		return ;
	first = b->top;
	second = b->top->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	b->top = second;
	if (b->size == 2)
		b->bot = first;
}

void	sb_print(t_stack *b)
{
	sb(b);
	printf("sb\n");
}

void	ss(t_stack *a, t_stack *b) //sa y sb a la vez
{
	sa(a);
	sb(b);
	printf("ss\n");//se separan los printf porque se tiene que ver ss al usarla, no "sa" "sb"
}

//ra -> pasa el primer elemento al último (de top a bot), todo sube una posición

void	ra(t_stack *a)
{
	t_node	*first;

	if (a->size < 2)
		return ;
	first = a->top;  //fist es lo que era el primer nodo
	a->top = a->top->next;  //top pasa a ser el que era segundo
	a->top->prev = NULL;
	a->bot->next = first; //bot pasa a ser el que era primero (como a->top ha cambiado, first es el nodo buscado)
	first->prev = a->bot;
	first->next = NULL; //al estar al final no apunta a nada mas (NULL)
	a->bot = first; //se actualiza bot
}

void	ra_print(t_stack *a)
{
	ra(a);
	printf("ra\n");
}

void	rb(t_stack *b)
{
	t_node	*first;

	if (b->size < 2)
		return ;
	first = b->top;
	b->top = b->top->next;
	b->top->prev = NULL;  //el nuevo top no tiene prev
	b->bot->next = first;
	first->prev = b->bot; //first (movido al final) apunta al viejo bot
	first->next = NULL;
	b->bot = first;
}

void	rb_print(t_stack *b)
{
	rb(b);
	printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	printf("rr\n");
}

//rra -> el último pasa a ser el primero, (todo baja una posición)

void	rra(t_stack *a)
{
	t_node	*last;

	if (a->size < 2)
		return ;
	last = a->bot;
	a->bot-> ???;
	a->top = last;
}

void	ra_print(t_stack *a)
{
	ra(a);
	printf("ra\n");
}

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
