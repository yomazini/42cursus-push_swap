/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:36:00 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/21 20:21:11 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	append_node(t_stack_node **stack, int n) //Define a function that searches for the last node to append to the linked list
{
	t_stack_node	*node; //To store a pointer to the new node to be created with the value `n`
	t_stack_node	*last_node1; //To store a pointer to the current last node of the stack

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node)); //Allocate memory for the new node
	if (!node)
		return ;
	node->next = NULL; //Set the next pointer of the new node to NULL because it will be the last node in the list
	node->value = n; //Set the `next` data of of the new node to `n` value
	node->cheapest = 0; // Initialise chaepest to 0;
	// other elements in the struct could be initialised as well but for now, this was the only one causing a valgrind issue
	if (!(*stack)) //Check if the stack is empty or currently pointing to NULL, indicating a first node needs to be found
	{
		*stack = node; //If empty, update the pointer *stack to point to the node, effectively making it the new head of the linked list
		node->previous = NULL; //Set the head node's previous pointer to NULL as it's the first node
	}
	else //If the stack is not empty, it means there are existing nodes in the linked list
	{
		last_node1 = last_node(*stack); //In which case, find the last node
		last_node1->next = node; //Append the new node to the last node
		node->previous = last_node1; //Update the previous pointer of the new node and complete the appending
	}
}

void	init_stack_a(t_stack_node **a, char **av)
{
	long	nmr;
	int		number;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
			free_error(a);
		nmr = ft_atol(av[i], a);
		if (nmr < INT_MIN || nmr > INT_MAX)
			free_error(a);
		number = (int)nmr;
		if (error_duplicate(*a, number))
			free_error(a);
		append_node(a, number);
		i++;
	}
}

void	set_cheapest_node(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;
	long			cheapest_value;

	cheapest_node = stack;
	cheapest_value = LONG_MAX;
	if (!stack)
		return ;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_node = stack;
			cheapest_value = stack->push_cost;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}
