/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:36:00 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/20 17:37:52 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!stack)
		return ;
	node = malloc(1);
	if (!node)
		return ;
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
		last = last_node(stack);
		last->next = node;
		node->previous = last;
	}
}

void	init_stack_a(t_stack_node **a, char **av)
{
	long	nmr;
	int		number;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
			free_error(a);
		nmr = ft_atol(av, a);
		if (nmr < INT_MIN || nmr > INT_MAX)
			free_error(a);
		number = nmr;
		if (duplicate_checker(*a, number))
			free_error(a);
		append_node(a, number);
		i++;
	}
}

void	set_cheapest_node(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;
	long			cheapest_value;

	cheapest_node = stack;
	cheapest_value = LONG_MAX;
	if (!stack)
		return ;
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
