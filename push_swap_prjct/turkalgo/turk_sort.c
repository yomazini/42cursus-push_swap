/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:20:41 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/29 19:32:11 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a_n_b(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
		rr(a, b, 0); //Rotate both `a` and `b` nodes
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_a_n_b(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
		rrr(a, b, 0); //Reverse rotate both `a` and `b` nodes
	current_index(*a); //Refresh current node positions
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
						char stack_name) //Define a function that moves the required node to the top of the stack
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median_line)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median_line)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}	
	}
}

 void	move_a_2_b(t_stack_node **a, t_stack_node **b) //Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
{
	t_stack_node	*cheapest_node; //To store the pointer to the cheapest `a` node

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->above_median_line 
		&& cheapest_node->target_node->above_median_line) //If both the cheapest `a` node and its target `b` node are above the median
		rotate_a_n_b(a, b, cheapest_node);
	else if (!(cheapest_node->above_median_line) 
		&& !(cheapest_node->target_node->above_median_line)) //If both the cheapest `a` node and its target `b` node are below the median
		rev_rotate_a_n_b(a, b, cheapest_node); //`rev_rotate_both` will execute if neither nodes are at the top
	prep_for_push(a, cheapest_node, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	prep_for_push(b, cheapest_node->target_node, 'b'); //Ensure the target node is at the top, ready for pushing
	pb(b, a, 0);
}

void	move_b_2_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a'); //Ensure `b`'s target `a` node is on top of the stack
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
