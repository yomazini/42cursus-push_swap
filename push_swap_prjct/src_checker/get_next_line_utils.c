/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:22:11 by ymazini           #+#    #+#             */
/*   Updated: 2025/02/01 22:49:08 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (NULL);
}

void	ft_error(t_stack_node **stack, char **strs)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	free_strs(strs);
	exit(0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1 [i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

int	has_duplicates(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*runner;

	current = stack;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

void	initialize_stack(t_stack_node **stack, int ac, char **av)
{
	char	**strs;
	int		i;
	long	n;

	while (--ac)
	{
		strs = ft_split(*++av, ' ');
		i = 0;
		while (strs[i])
		{
			if (!handle_str(strs[i]))
				ft_error(stack, strs);
			n = ft_atol1(strs[i++], stack, strs);
			if (n > INT_MAX || n < INT_MIN)
				ft_error(stack, strs);
			append_node(stack, (int)n);
		}
		free_strs(strs);
	}
}
