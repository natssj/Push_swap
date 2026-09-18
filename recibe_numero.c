#include <stdio.h>
#include <stdlib.h>
 
typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;
 
t_node *new_node(int value)
{
    t_node *node;
 
    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}
 
// void add_node(t_node **head, t_node *new)
// {
//     new->next = *head;
//     *head = new;
// }

void add_node_last(t_node **head, t_node *new)
{
	t_node	*last;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new; //sirve para la primera llamada (en el main inicializo con head = NULL)
		return ;
	}
	last = *head;
	while(last->next)
		last = last->next;
    last->next = new;
}
 
int main(int argc, char **argv)
{
    t_node *head_a;
	t_node *head_b;
    t_node *tmp;
    int     i;
 
    head_a = NULL; //la lista empieza vacia
	head_b = NULL;
    i = 1; //se empieza a leer desde argv 1 (no cuenta el nombre del programa)
    while (i < argc)
    {
        tmp = new_node(atoi(argv[i]));
        add_node_last(&head_a, tmp);
        i++;
    }
    tmp = head_a;
	printf("Stack A:\n");
    while (tmp)
    {
		
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
	tmp = head_b;
	printf("Stack B:\n");
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
    return (0);
}
