/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:09:00 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/29 17:20:15 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	ft_swap_node(t_stack_node **head)
// {
// 	t_stack_node	*tmp;
// 	t_stack_node	*prev_1;
// 	t_stack_node	*next_1;

// 	if (!(*head) || !((*head)->next))
// 		return ;
// 	tmp = *head;
// 	prev_1 = (*head)->previous;
// 	next_1 = (*head)->next->next;
// 	(*head) = (*head)->next;
// 	(*head)->next = tmp;
// 	(*head)->previous = prev_1;
// 	tmp->next = next_1;
// 	tmp->previous = *head;
// 	if (next_1)
// 		next_1->previous = tmp;
// 	if (prev_1)
// 		prev_1->next = *head;
// }

void	ft_swap_node(t_stack_node **head)
{
	if (!*head || !(*head)->next) //Check if the stop node, or second node of a stack exists
		return ;
	*head = (*head)->next; //Update `head` to point to the next node, effectively swapping the first and second nodes
	(*head)->previous->previous = *head; //Update the `prev` pointer of the node before the `new head` to point to the `new head`
	(*head)->previous->next = (*head)->next; //Update the `next` pointer of the node before the `new head` to skip the `old head` and point directly to the `new head`
	if ((*head)->next) //Check if there's a `next` node after the `new head` and
		(*head)->next->previous = (*head)->previous; //If so, update its `prev` pointer to point back to the `new head`
	(*head)->next = (*head)->previous; //Update the `next` pointer of the `new head` to point to the `old head`, effectively reversing their positions
	(*head)->previous = NULL; //Sets the `prev` pointer of the `new head` to `NULL` completing the swap
}

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
		ft_putstr("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, int testing)
{
	ft_swap_node(a);
	ft_swap_node(b);
	if (!testing)
		ft_putstr("ss\n");
}
