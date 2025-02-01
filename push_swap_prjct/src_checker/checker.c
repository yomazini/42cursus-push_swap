/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:22:36 by ymazini           #+#    #+#             */
/*   Updated: 2025/02/01 23:08:51 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	parse_command(t_stack_node **a, t_stack_node **b, char *command)
{
	if (!ft_strncmp(command, "pa\n", 3))
		pa(a, b, 1);
	else if (!ft_strncmp(command, "pb\n", 3))
		pb(b, a, 1);
	else if (!ft_strncmp(command, "sa\n", 3))
		sa(a, 1);
	else if (!ft_strncmp(command, "sb\n", 3))
		sb(b, 1);
	else if (!ft_strncmp(command, "ss\n", 3))
		ss(a, b, 1);
	else if (!ft_strncmp(command, "ra\n", 3))
		ra(a, 1);
	else if (!ft_strncmp(command, "rb\n", 3))
		rb(b, 1);
	else if (!ft_strncmp(command, "rr\n", 3))
		rr(a, b, 1);
	else if (!ft_strncmp(command, "rra\n", 4))
		rra(a, 1);
	else if (!ft_strncmp(command, "rrb\n", 4))
		rrb(b, 1);
	else if (!ft_strncmp(command, "rrr\n", 4))
		rrr(a, b, 1);
	else
		error(a, b, command);
}

static int	check_empty_arguments(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (1);
}

static void	process_commands(t_stack_node **a, t_stack_node **b)
{
	char	*next_line;

	next_line = get_next_line(0);
	while (next_line)
	{
		parse_command(a, b, next_line);
		free(next_line);
		next_line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				len;

	if (ac > 1)
	{
		check_empty_arguments(ac, av);
		len = 0;
		stack_a = NULL;
		stack_b = NULL;
		initialize_stack(&stack_a, ac, av);
		if (!stack_a || has_duplicates(stack_a))
			ft_error(&stack_a, NULL);
		len = stack_length(stack_a);
		process_commands(&stack_a, &stack_b);
		if (stack_sorted(stack_a) && stack_b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
