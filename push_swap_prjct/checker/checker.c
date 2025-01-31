/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:36:05 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/31 21:18:14 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	clean_and_exit(t_stack_node **a, t_stack_node **b, int status)
{
	free_stack(a);
	free_stack(b);
	if (status == 1)
		ft_putstr("Error\n");
	exit(status);
}

static void	check_result(t_stack_node *a, t_stack_node *b)
{
	if (stack_sorted(a) && !b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_av;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	split_av = split_args(ac - 1, av + 1);
	if (!split_av || !*split_av)
		clean_and_exit(&a, &b, 1);
	init_stack_a(&a, split_av, split_av);
	free_strs(split_av);
	execute_commands(&a, &b);
	check_result(a, b);
	clean_and_exit(&a, &b, 0);
	return (0);
}
