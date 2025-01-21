/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiase_b_2_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:29:46 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/21 17:51:50 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
    t_stack_node	*target_node;
    t_stack_node	*current_a;
    long			best_match_index;

    while (b)
    {
        best_match_index = LONG_MAX;
        current_a = a;
        while (current_a)
        {
            if (current_a->value > b->value && 
                current_a->value < best_match_index)
            {
                best_match_index = current_a->value;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match_index == LONG_MIN)
            b->target_node = find_min_node(a);
        else
            b->target_node = target_node;
        b = b->next;
    }
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
