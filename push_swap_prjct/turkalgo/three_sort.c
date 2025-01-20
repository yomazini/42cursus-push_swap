/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:18:08 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/20 18:19:14 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_on_top(t_stack_node **a)
{
	while ((*a)->value != find_min_node((*a)->value))
	{
		if (find_min_node(*a)->above_median_line)
			ra(a, 0);
		else
			rra(a, 0);
	}
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = find_max_node(a);
	if (biggest == (*a))
		ra(*a, 0);
	else if (biggest == (*a)->next)
		rra(*a, 0);
	if ((*a)->value > (*a)->next->value)
		sa(*a, 0);
}
