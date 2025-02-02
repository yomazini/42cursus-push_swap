/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:02:59 by ymazini           #+#    #+#             */
/*   Updated: 2025/02/02 18:10:00 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rev_rotate_node(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*new_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	new_last = last->previous;
	new_last->next = NULL;
	last->previous = NULL;
	last->next = *stack;
	(*stack)->previous = last;
	*stack = last;
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
