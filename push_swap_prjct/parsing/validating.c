/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:19:21 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/20 17:17:58 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	syntax_error(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] != '+' || str[i] != '-' || ft_isdigit(str[i])))
		return (1);
	if (((str[i] == '+' || str[i] == '-') && !(ft_isdigit(str[i + 1]))))
		return (1);
	i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
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

void	free_error(t_stack_node **a)
{
	free_stack(a);
	ft_putstr("Error\n");
	exit(2);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	current = stack;
	if (!stack)
		return ;
	while (current)
	{
		tmp = current->next;
		current->value = -987652;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

long	ft_atol(char *str, t_stack_node **a)
{
	long	nmr;
	int		i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	if (ft_strlen(str) > 11)
		free_error(a);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}
