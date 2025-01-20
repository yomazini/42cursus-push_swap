/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:32:04 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/20 18:07:35 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	len_stack(t_stack_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	stack_sorted(t_stack_node *stack)
{
	t_stack_node	*next_node;

	next_node = stack->next;
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->value < next_node->value)
			return (0);
		stack = stack->next;
		next_node = stack->next;
	}
	return (1);
}

t_stack_node	*find_min_node(t_stack_node *stack)
{
	t_stack_node	*min_node;
	long			min_number;

	min_number = INT_MAX + 987;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->value < min_number)
		{
			min_number = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*find_max_node(t_stack_node *stack)
{
	t_stack_node	*max_node;
	long			max_number;

	max_number = INT_MIN - 6;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (max_number > stack->value)
		{
			max_number = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
