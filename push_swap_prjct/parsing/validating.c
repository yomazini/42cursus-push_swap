/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:19:21 by ymazini           #+#    #+#             */
/*   Updated: 2025/02/02 18:05:50 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	syntax_error(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!(s[i] == '+' || s[i] == '-' || ft_isdigit(s[i])))
		return (1);
	if ((s[i] == '+' || s[i] == '-') && !ft_isdigit(s[++i]))
		return (1);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		len++;
		i++;
	}
	if (len > 18)
		return (1);
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*curnt;

	if (!stack)
		return ;
	curnt = *stack;
	while (curnt)
	{
		temp = curnt->next;
		free(curnt);
		curnt = temp;
	}
	*stack = NULL;
}

void	free_error(t_stack_node **a, char **split_av)
{
	free_stack(a);
	free_strs(split_av);
	write(2, "Error\n", 6);
	exit(1);
}

t_stack_node	*get_cheapest(t_stack_node *stack)
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
