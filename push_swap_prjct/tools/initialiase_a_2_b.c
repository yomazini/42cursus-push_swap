/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiase_a_2_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:21:38 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/29 19:31:42 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i; //To store the index of the current node
	int	median; //To store the position of the median of the stack

	i = 0; //The first index is `0`
	if (!stack) //Check for am empty stack
		return ;
	median = len_stack(stack) / 2; //Calculate the median by dividing the length of a stack by 2
	while (stack) //Loop through all the nodes until the end of the stack is reached
	{
		stack->indexing = i; //Assign the current index value to the current node
		if (i <= median) //Check whether the current node is above or below the median
			stack->above_median_line = 1; //If above, set the above_median data of the node to true
		else
			stack->above_median_line = 0; //If below, set the above_median data of the node to false
		stack = stack->next; //Move to the next node for indexing
		++i; //Increment the index value to set the next node with
	}
}


void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b; //To store the pointer to the current node in stack `b` and iterate through each node following
	t_stack_node	*target_node; //To store the pointer to the target node in stack `b`
	long			best_match_index; //In this case, the best match indexe stores the value of the "closest smaller number" so far

	while (a) //As long as we have nodes in stack `a`
	{
		best_match_index = LONG_MIN; //Assign the smallest `long` as the closest smaller number so far
		current_b = b; //Assign to `current_b` the current `b` node
		while (current_b) //Iteratively search through all the nodes in stack `b` until the end of the stack is reached
		{
			if (current_b->value < a->value 
				&& current_b->value > best_match_index) //Check if `b` node is smaller than `a` node && bigger than the closest smaller number so far
			{
				best_match_index = current_b->value; //If so, update the value of the closest smaller number so far
				target_node = current_b; //Assign the current `b` node as the `target_node`
			}
			current_b = current_b->next; //Move to the next `b` node for comparison, until a "closer smaller number" is found
		}
		if (best_match_index == LONG_MIN) //Check if the LONG_MIN hasn't changed, it means we haven't found anything smaller
			a->target_node = find_max_node(b); //If so, find the biggest `nbr` and set this as the target node
		else
			a->target_node = target_node; //If no "closer smaller number" is found, and the best match has changed
		a = a->next; //Move to the next `a` node to find it's target `b` node
	}
}
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

void	init_node_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest_node(a);
}
