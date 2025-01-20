/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:09:54 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/20 18:10:32 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*push_node;

	if (!(*src))
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	push_node->previous = NULL;
	if (!(*dst))
	{
		(*dst) = push_node;
		(*dst)->next = NULL;
	}
	else
	{
		push_node->next = (*dst);
		push_node->next->previous = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, int testing)
{
	push(a, b);
	if (!testing)
		ft_putstr("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, int testing)
{
	push(b, a);
	if (!testing)
		ft_putstr("pb\n");
}
