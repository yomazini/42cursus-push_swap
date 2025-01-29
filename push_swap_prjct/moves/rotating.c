/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:58:24 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/29 19:50:44 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	ft_rotate_node(t_stack_node **stack) //Define a function that rotates the stack's top node to the bottom of the stack
{
	t_stack_node	*last_node1; //To store a pointer to the last node of a stack

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last_node1 = last_node(*stack); 
	last_node1->next = *stack; //Assign to the last node, its `next` attribute as the top node, effectively setting the current top node as the last node
	*stack = (*stack)->next; //Assign to the pointer of the top node, the node after it (second from the top)
	(*stack)->previous = NULL; //Complete setting the current top node by detaching it from its previous top node
	last_node1->next->previous = last_node1; //Reconnect the second node's prev pointer to point to what was previously the last node in the stack
	last_node1->next->next = NULL; //Assign to the `next` attribute of the current last node, `NULL` effectively setting it as the current last node, and properly null terminating the stack
}		

void	ra(t_stack_node **a, int testing) //Rotate the top `a` node to the bottom of the stack, and print the instruction
{
	ft_rotate_node(a);
	if (!testing)
		ft_putstr("ra\n");
}

void	rb(t_stack_node **b, int testing) //Rotate the top `b` node to the bottom of the stack, and print the instruction
{
	ft_rotate_node(b);
	if (!testing)
		ft_putstr("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, int testing) //Stimultaneously rotate both the top `a` and `b` nodes to the bottom of the stack, and print the instruction
{
	ft_rotate_node(a);
	ft_rotate_node(b);
	if (!testing)
		ft_putstr("rr\n");
}
