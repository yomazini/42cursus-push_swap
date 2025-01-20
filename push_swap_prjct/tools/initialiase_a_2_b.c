/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiase_a_2_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:21:38 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/20 17:24:44 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_cheapest_node(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;
	long			cheapest_value;

	cheapest_node = stack;
	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_node = stack;
			cheapest_value = stack->push_cost;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int		len_a;
	int		len_b;

	len_a = len_stack(a);
	len_b = len_stack(b);
	while (a)
	{
		a->push_cost = a->indexing;
		if (!(a->above_median_line))
			a->push_cost = len_a - (a->push_cost);
		if (a->target_node->above_median_line)
			a->push_cost = a->push_cost + a->target_node->indexing;
		else
			a->push_cost = a->push_cost + len_b - (a->target_node->indexing);
		a = a->indexing;
	}
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MAX;
		current_b = b;
		while (current_b)
		{
			if (a->value > current_b->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MAX)
			a->target_node = find_max_node(b);
		else
			a->target_node = target_node;
		a = a -> next;
	}
}

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	median = len_stack(stack) / 2;
	while (stack)
	{
		stack->indexing = i;
		if (!stack)
			return ;
		if (i <= median)
			stack->above_median_line = 1;
		else
			stack->above_median_line = 0;
		stack = stack->next;
		i++;
	}
}

void	init_node_a(a, b)
{
	currrent_index(a);
	currrent_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
