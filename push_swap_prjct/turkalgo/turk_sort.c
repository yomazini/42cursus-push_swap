/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:20:41 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/21 19:31:09 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a_n_b(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (cheapest_node->target_node != (*b) && (*a) != cheapest_node)
		rr(a, b, 0);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_a_n_b(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (cheapest_node->target_node != (*b) && (*a) != cheapest_node)
		rrr(a, b, 0);
	current_index(*a);
	current_index(*b);
}

t_stack_node	*get_cheapest(t_stack_node *stack) //Define a function that searches for the cheapest node, that is set by bool
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median_line)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median_line)
				rb(stack, 0);
			else
				rrb(stack, 0);
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
	else if (!(cheapest_node->above_median_line
			&& cheapest_node->target_node->above_median_line))
		rev_rotate_a_n_b(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node, 'b');
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
		pb(a, b, 0);
	if (len-- > 3 && !stack_sorted(*a))
		pb(a, b, 0);
	while (len-- && !stack_sorted(*a))
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
