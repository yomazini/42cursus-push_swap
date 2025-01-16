#include "push_swap.h"

void	init_stack_a(t_stack_node **a, char **av)
{
	long	nmr;
	int		number;
	int		i;

	i = 0; // we start from 0 meaning because we send av + 1 ptr so start at first one;
	while (av[i])
	{
		if (syntax_error(av[i]))
			free_error(a);
		nmr = ft_atol(av[i]);// here can also add strlen(check av if more than integer length and return automatically)
		if (nmr < INT_MIN || nmr > INT_MAX )
			free_error(a);
		number = nmr;
		if(duplicate_checker(*a, number))
			free_error(a);
		append_node(a, number); // similar to lst_addback (check it as well)
		i++;
	}
}