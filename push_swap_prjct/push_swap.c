/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:24:22 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/20 15:25:10 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !ft_strlen(av[1])))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	prep_stack_a(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (stack_length(a) == 2)
			sa(&a, 0);
		else if (stack_length(a) == 3)
			three_sort(&a);
		else
			turk_sort(&a, &b);
	}
	clean_stack(&a);
	return (0);
}
