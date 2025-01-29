/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:58:24 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/29 22:32:54 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_node(t_stack_node **stack)
{
	t_stack_node	*last_node1;

	if (!*stack || !(*stack)->next)
		return ;
	last_node1 = last_node(*stack);
	last_node1->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last_node1->next->previous = last_node1;
	last_node1->next->next = NULL;
}

void	ra(t_stack_node **a, int testing)
{
	ft_rotate_node(a);
	if (!testing)
		ft_putstr("ra\n");
}

void	rb(t_stack_node **b, int testing)
{
	ft_rotate_node(b);
	if (!testing)
		ft_putstr("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, int testing)
{
	ft_rotate_node(a);
	ft_rotate_node(b);
	if (!testing)
		ft_putstr("rr\n");
}
