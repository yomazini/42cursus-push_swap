/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:20:41 by ymazini           #+#    #+#             */
/*   Updated: 2025/02/02 16:26:09 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'b')
		{
			if (top_node->above_median_line)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
		else if (stack_name == 'a')
		{
			if (top_node->above_median_line)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
	}
}

void	move_a_2_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median_line
		&& cheapest_node->target_node->above_median_line)
		rotate_a_n_b(a, b, cheapest_node);
	else if (!(cheapest_node->above_median_line)
		&& !(cheapest_node->target_node->above_median_line))
		rev_rotate_a_n_b(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, 0);
}

void	move_b_2_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, 0);
}

void	turk_sort(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = len_stack(*a);
	if (len-- > 3 && !stack_sorted(*a))
		pb(b, a, 0);
	if (len-- > 3 && !stack_sorted(*a))
		pb(b, a, 0);
	while (len-- > 3 && !stack_sorted(*a))
	{
		init_node_a(*a, *b);
		move_a_2_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_2_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
