/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:02:59 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/21 15:59:13 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	ft_rev_rotate_node(t_stack_node **head)
// {
// 	t_stack_node	*last;

// 	if (!*head || !(*head)->next)
// 		return ;
// 	last = last_node(head);
// 	last->previous->next = NULL;
// 	last->previous = NULL;
// 	last->next = (*head);
// 	(*head) = last;
// 	last->next->previous = last;
// }

void ft_rev_rotate_node(t_stack_node **head)
{
    t_stack_node *last;

    if (!*head || !(*head)->next)
        return;
    last = last_node(*head); // Correct: Dereference `head`
    last->previous->next = NULL;
    last->previous = NULL;
    last->next = (*head);
    (*head) = last;
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
