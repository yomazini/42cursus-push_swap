/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:31:13 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/29 19:09:03 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	stack_length(t_stack_node *stack)
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

t_stack_node	*last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// t_stack_node	*ft_lstnew(void *content)
// {
// 	t_stack_node	*new;

// 	new = malloc(sizeof(t_stack_node));
// 	if (!new)
// 		return (NULL);
// 	new->value = content;
// 	new->next = NULL;
// 	return (new);
// }
