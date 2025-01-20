/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:20:41 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/20 20:03:31 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//rotate_a_n_b
void	rotate_a_n_b(t_stack_node **a, t_stack_node **b)
{
	while ((*a)->target_node != )
	{
		/* code */
	}
	
}
//rev_rotate_a_n_b

// move_a_2_b

// move_b_2_a


// sort_stack_turk

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = len_stack(a);
	if (len-- > 3 && !stack_sorted(a))
		pb(a, b, 0);
	if (len-- > 3 && !stack_sorted(a))
		pb(a, b, 0);
	while (len-- && !stack_sorted(a))
	{
		init_node_a(a, b);
		move_a_2_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_node_b(a, b);
		move_b_2_a(a, b);
	}
	curreent_position(a);
	move_min_to_top(a);
}
