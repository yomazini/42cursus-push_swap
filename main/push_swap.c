#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;
	
	if (ac == 1 || (ac == 2 && !ft_strlen(av[1])))
		exit(2);
		// this is will not work with malformed args (fix it later)
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack_a(&a,av + 1);
	// this is will check if work with stack 2 || 3 || 5 (add it later) || other --> turk algo;
	if (!stack_sorted(a))
	{
		if (stack_length(a) == 2)
			sa(&a, 0);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}

//TODO: must get details of else in cost analysis; what mwaning of it