#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h" // Ensure this includes necessary headers and `ft_putstr`

void    ft_putstr(char *str)
{
        while(*str)
        {
                write(1,str,1);
                str++;
        }
}


void	ft_swap_node(t_stack_node **head)
{
	t_stack_node *tmp;
	t_stack_node *prev_1;
	t_stack_node *next_1;

	if (!(*head) || !((*head)->next))
		return ;

	tmp = *head;
	prev_1 = (*head)->previous;
	next_1 = (*head)->next->next;

	(*head) = (*head)->next; // Update head to point to the second node
	(*head)->next = tmp; // Update new head's next to point to the old head
	(*head)->previous = prev_1; // Update new head's prev to point to the old head's prev

	tmp->next = next_1; // Update old head's next to point to next_1
	tmp->previous = *head; // Update old head's prev to point to the new head

	if (next_1) // Update next_1's previous pointer if it exists
		next_1->previous = tmp;
	if (prev_1) // Update prev_1's next pointer if it exists
		prev_1->next = *head;
}


//finish all sa sb ss
void	sa(t_stack_node **a, int testing)
{
	ft_swap_node(a);
	if (!testing)
		ft_putstr("sa\n");
}

void	sb(t_stack_node **b, int testing)
{
	ft_swap_node(b);
	if (!testing)
		ft_putstr("sa\n");
}

void	ss(t_stack_node **a, t_stack_node **b,int testing)
{

	ft_swap_node(a);
	ft_swap_node(b);
	if (!testing)
		ft_putstr("ss\n");
}


// Helper function to create a new node
t_stack_node *create_node(int value) {
    t_stack_node *node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

// Helper function to print the stack
void print_stack(t_stack_node *head) {
    t_stack_node *current = head;
    printf("Stack: ");
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Function to clean up memory
void free_stack(t_stack_node *head) {
    t_stack_node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void) {
    t_stack_node *a = create_node(1);
    t_stack_node *b = create_node(4);
    t_stack_node *c = create_node(3);
    t_stack_node *d = create_node(2);
    t_stack_node *stack_b = NULL; // Empty stack B

    // Link stack A
    a->next = b;
    b->previous = a;
    b->next = c;
    c->previous = b;
    c->next = d;
    d->previous = c;

    printf("Initial Stack A:\n");
    print_stack(a);

    // Test `sa`
    printf("\nTesting sa (swap top two of stack A):\n");
    sa(&a, 0); // Testing = 0 to print operation
    print_stack(a);

    // Test `sb` (requires stack B to have at least 2 nodes)
    printf("\nTesting sb (swap top two of stack B):\n");
    stack_b = create_node(5);
    stack_b->next = create_node(6);
    stack_b->next->previous = stack_b;
    print_stack(stack_b);
    sb(&stack_b, 0); // Testing = 0 to print operation
    print_stack(stack_b);

    // Test `ss` (swap both stacks simultaneously)
    printf("\nTesting ss (swap top two of both stacks):\n");
    ss(&a, &stack_b, 0); // Testing = 0 to print operation
    print_stack(a);
    print_stack(stack_b);

    // Free memory
    free_stack(a);
    free_stack(stack_b);

    return 0;
}
