/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiase_a_2_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:21:38 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/21 21:12:46 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

 void	cost_analysis_a(t_stack_node *a, t_stack_node *b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	int	len_a; //To store the length of stack `a`
	int	len_b; //To store the length of stack `b`

	len_a = len_stack(a);
	len_b = len_stack(b);
	while (a) //Loop through each node until the end of the stack is reached
	{
		a->push_cost = a->indexing; //Assign the current `a` node's push cost, its' index value
		if (!(a->above_median_line)) //Check if the above_median data is false, meaning it is below median
			a->push_cost = len_a - (a->indexing); //If so, update `a` node's push cost to the stack's length - index
		if (a->target_node->above_median_line) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
			a->push_cost += a->target_node->indexing; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
		else //If `a` node is indeed above median and its target `b` node is below median
			a->push_cost += len_b - (a->target_node->indexing); //Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
		a = a->next; //Move to the next `a` node for its cost analysis
	}
}


void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
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
		if (best_match_index == LONG_MIN)
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
	if (!stack)
		return ;
	median = len_stack(stack) / 2;
	while (stack)
	{
		stack->indexing = i;
		if (i <= median)
			stack->above_median_line = 1;
		else
			stack->above_median_line = 0;
		stack = stack->next;
		i++;
	}
}

void	init_node_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest_node(a);
}
