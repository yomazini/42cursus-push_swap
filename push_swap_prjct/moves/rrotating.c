/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:02:59 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/21 21:01:28 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	ft_rev_rotate_node(t_stack_node **head)
// {
// 	t_stack_node	*last;

// 	if (!*head || !(*head)->next)
// 		return ;
// 	last = last_node(head);
// 	last->previous->next = NULL;
// 	last->previous = NULL;
// 	last->next = (*head);
// 	(*head) = last;
// 	last->next->previous = last;
// }

void ft_rev_rotate_node(t_stack_node **stack)
{
	t_stack_node	*last; //To store the pointer to the last node

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last = last_node(*stack);
	last->previous->next = NULL; //Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
	last->next = *stack; //Assign to its own `next` attribute as the top node of the stack
	last->previous = NULL; //Detach itself from the node before it
	*stack = last;  //Complete appending itself to the top of the stack, and now holds the pointer to the top node
	last->next->previous = last; //Update the current last node of the stack
}

void	rra(t_stack_node **a, int testing)
{
	ft_rev_rotate_node(a);
	if (!testing)
		ft_putstr("rra\n");
}

void	rrb(t_stack_node **b, int testing)
{
	ft_rev_rotate_node(b);
	if (!testing)
		ft_putstr("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, int testing)
{
	ft_rev_rotate_node(a);
	ft_rev_rotate_node(b);
	if (!testing)
		ft_putstr("rrr\n");
}
