/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:58:24 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/20 22:48:16 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_node(t_stack_node **head)
{
	t_stack_node	*last;

	if (!*head || !(*head)->next)
		return ;
	last = last_node(*head); // Dereference `head` to pass the correct type
	last->next = (*head);
	(*head) = (*head)->next;
	(*head)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
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

void	rrr(t_stack_node **a, t_stack_node **b, int testing)
{
	ft_rev_rotate_node(a);
	ft_rev_rotate_node(b);
	if (!testing)
		ft_putstr("rrr\n");
}
