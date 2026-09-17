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
 
void add_node(t_node **head, t_node *new)
{
    new->next = *head;
    *head = new;
}
 
int main(int argc, char **argv)
{
    t_node *head;
    t_node *tmp;
    int     i;
 
    head = NULL; //la lista empieza vacia
    i = 1; //se empieza a leer desde argv 1 (no cuenta el nombre del programa)
    while (i < argc)
    {
        tmp = new_node(atoi(argv[i]));
        add_node(&head, tmp);
        i++;
    }
    tmp = head;
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
    return (0);
}
