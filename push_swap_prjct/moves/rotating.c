/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:58:24 by ymazini           #+#    #+#             */
/*   Updated: 2025/02/02 18:09:51 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_node(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = last_node(*stack);
	*stack = first->next;
	(*stack)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
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
