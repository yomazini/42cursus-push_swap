/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:19:21 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/31 15:32:05 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int syntax_error(char *str_n)
{
    int len = 0;
    char *s = str_n;

    if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
        return (1);
    if ((*s == '+' || *s == '-') && !(s[1] >= '0' && s[1] <= '9'))
        return (1);
    if (*s == '+' || *s == '-')
        s++;
    while (*s)
    {
        if (!(*s >= '0' && *s <= '9'))
            return (1);
        len++;
        s++;
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
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_error(t_stack_node **a, char **split_av)
{
    free_stack(a);
    free_strs(split_av);
    ft_putstr("Error\n");
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
