/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:38:24 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/09/28 15:38:28 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//todas las operaciones juntas
//en esta version no estan los contadores de --bench


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
	a->bot = a->bot->prev;
	a->bot->next = NULL;
	last->next = a->top;
	a->top->prev = last;
	last->prev = NULL;
	a->top = last;
}

void	rra_print(t_stack *a)
{
	rra(a);
	printf("rra\n");
}

void	rrb(t_stack *b)
{
	t_node	*last;

	if (b->size < 2)
		return ;
	last = b->bot;
	b->bot = b->bot->prev;
	b->bot->next = NULL;
	last->next = b->top;
	b->top->prev = last;
	last->prev = NULL;
	b->top = last;
}

void	rrb_print(t_stack *b)
{
	rrb(b);
	printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	printf("rrr\n");
}
