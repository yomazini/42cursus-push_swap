/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:02:59 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/29 22:33:44 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rev_rotate_node(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	last->previous->next = NULL;
	last->next = *stack;
	last->previous = NULL;
	*stack = last;
	last->next->previous = last;
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
