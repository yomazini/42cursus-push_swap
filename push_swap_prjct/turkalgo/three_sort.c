/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:18:08 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/21 20:00:10 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_on_top(t_stack_node **a)
{
	while ((*a)->value != find_min_node(*a)->value)
	{
		if (find_min_node(*a)->above_median_line)
			ra(a, 0);
		else
			rra(a, 0);
	}
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node; //To store a pointer to the biggest node in stack `a`

	biggest_node = find_max_node(*a);
	if (biggest_node == *a) //Check if the current node is the biggest
		ra(a, 0); //If so, rotate the top node to the bottom of the stack
	else if ((*a)->next == biggest_node) //Check if the second node is the biggest
		rra(a, 0); //If so, reverse rotate the bottom node, to the top of the stack
	if ((*a)->value > (*a)->next->value) //Check if the bottom node is the biggest, but the top node is higher than the second node
		sa(a, 0); //If so, simply swap the top and second nodes
}
