/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:09:54 by ymazini           #+#    #+#             */
/*   Updated: 2025/02/02 18:09:03 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*to_push;

	if (!*src)
		return ;
	to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	to_push->previous = NULL;
	if (!*dst)
	{
		*dst = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *dst;
		(*dst)->previous = to_push;
		*dst = to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, int testing)
{
	push(a, b);
	if (!testing)
		ft_putstr("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, int testing)
{
	push(b, a);
	if (!testing)
		ft_putstr("pb\n");
}
