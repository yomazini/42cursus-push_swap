/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:09:00 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/29 20:24:10 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_node(t_stack_node **head)
{
	if (!*head || !(*head)->next) //Check if the stop node, or second node of a stack exists
		return ;
	*head = (*head)->next; //Update `head` to point to the next node, effectively swapping the first and second nodes
	(*head)->previous->previous = *head; //Update the `previous` pointer of the node before the `new head` to point to the `new head`
	(*head)->previous->next = (*head)->next; //Update the `next` pointer of the node before the `new head` to skip the `old head` and point directly to the `new head`
	if ((*head)->next) //Check if there's a `next` node after the `new head` and
		(*head)->next->previous = (*head)->previous; //If so, update its `previous` pointer to point back to the `new head`
	(*head)->next = (*head)->previous; //Update the `next` pointer of the `new head` to point to the `old head`, effectively reversing their positions
	(*head)->previous = NULL; //Sets the `previous` pointer of the `new head` to `NULL` completing the swap
}

void	sa(t_stack_node	**a, int testing) //Swap 
//2147483647 -2147483648
//the first two nodes of stack `a` and print the instruction
{
	ft_swap_node(a);
	if (!testing)
		ft_putstr("sa\n");
}

void	sb(t_stack_node **b, int testing) //Swap the first two nodes of stack `b` and print the instruction
{
	ft_swap_node(b);
	if (!testing)
		ft_putstr("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, int testing) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
	ft_swap_node(a);
	ft_swap_node(b);
	if (!testing)
		ft_putstr("ss\n");
}
