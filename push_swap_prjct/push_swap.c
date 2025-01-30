/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:24:22 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/30 20:43:53 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_av;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	split_av = split_args(ac, av);
	if (!split_av || !*split_av)
	{
		free_strs(split_av);
		ft_putstr("Error\n");
		return (1);
	}
	init_stack_a(&a, split_av);	
	free_strs(split_av);
	if (!stack_sorted(a))
	{
		if (stack_length(a) == 2)
			sa(&a, 0);
		else if (stack_length(a) == 3)
			sort_three(&a);
		else
			turk_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
