/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:36:00 by ymazini           #+#    #+#             */
/*   Updated: 2025/02/02 18:08:23 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node1;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		free_error(stack, NULL);
	node->next = NULL;
	node->value = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last_node1 = last_node(*stack);
		last_node1->next = node;
		node->previous = last_node1;
	}
}

void	init_stack_a(t_stack_node **a, char **av, char **split_av)
{
	long	nmr;
	int		number;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
			free_error(a, split_av);
		nmr = ft_atol(av[i]);
		if (nmr < INT_MIN || nmr > INT_MAX)
			free_error(a, split_av);
		number = (int)nmr;
		if (error_duplicate(*a, number))
			free_error(a, split_av);
		append_node(a, number);
		i++;
	}
}

void	set_cheapest_node(t_stack_node *stack)
{
	long			min_cost;
	t_stack_node	*cheapest;

	if (!stack)
		return ;
	min_cost = LONG_MAX;
	cheapest = stack;
	while (stack)
	{
		if (stack->push_cost < min_cost)
		{
			min_cost = stack->push_cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = 1;
}

void	rotate_a_n_b(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rr(a, b, 0);
	current_index(*b);
	current_index(*a);
}

void	rev_rotate_a_n_b(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b, 0);
	current_index(*b);
	current_index(*a);
}
