/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:09:00 by ymazini           #+#    #+#             */
/*   Updated: 2025/02/02 16:20:26 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_node(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->previous = first->previous;
	first->previous = second;
	second->next = first;
	*head = second;
}

void	sa(t_stack_node	**a, int testing)
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
