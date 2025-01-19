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
		nmr = ft_atol(av, a); // here can also add strlen(check av if more than integer length and return automatically)
		if (nmr < INT_MIN || nmr > INT_MAX )
			free_error(a);
		number = nmr;
		if(duplicate_checker(*a, number))
			free_error(a);
		append_node(a, number); // similar to lst_addback (check it as well)
		i++;
	}
}

int	syntax_error(char *str)
{
	int i;

	i = 0;
	if (!(str[i] != '+' || str[i] != '-' || ft_isdigit(str[i])))
		return(1);
	if (((str[i] == '+' || str[i] == '-') && !(ft_isdigit(str[i + 1]))))
		return (1);
	i++;
	while(str[i])
	{
		if(!ft_isdigit(str[i]))
			return 1;
		i++;
	}
	return 0;
}

int	error_duplicate(t_stack_node *a, int n)
{
	if(!a)
		return 0;
	while(a)
	{
		if (a->value == n)
			return 1;
		a = a->next;
	}
	return 0;
}

long	ft_atol(char *str, t_stack_node **a)
{
	long	nmr;
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	if (ft_strlen(str) > 11) // to protec if none integer and overflow of the long
	{
		free_error(a);
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while(str[i])
	{
		res = res *10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

// void    ft_putstr(char *str)
// {
//         while(*str)
//         {
//                 write(1,str,1);
//                 str++;
//         }
// }

void	free_error(t_stack_node **a)
{
	free_stack(a);
	ft_putstr("Error\n");
	exit(2);
}

void	free_stack(t_stack_node **stack)
{
	if (!stack)
		return;

	t_stack_node *current;
	t_stack_node *tmp;
	current = stack;
	while(current)
	{
		tmp = current->next;
		current->value = -987652; // best practice for debugging
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

//chack stack is sorted 

//TODO: check from HERE 

int	stack_sorted(t_stack_node *stack)
{
	t_stack_node *next_node;
	next_node = stack->next;
	if (!stack)
		return 0;
	while (stack->next)
	{
		if (stack->value < next_node->value)
			return (0);
		stack = stack->next;
		next_node = stack->next;
	}
	return 1;
}

//check stack length or can choose lstsize here

int len_stack(t_stack_node *stack)
{
	int i = 0;
	if (!stack)
		return 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return i;
}

//find min in stack 

t_stack_node *find_min(t_stack_node *stack)
{
	
}

//find max in stack

//sort 2 in stack

//sort 3 in stack


t_stack_node *last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while(stack->next)
		stack = stack->next;
	return (stack);
}

// apendthe node to last

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node *node;
	t_stack_node *last;

	if (!stack)
		return ;
	node = malloc (1);
	if (!node)
		return;
	node->next = NULL;
	node->value = n;
	node->cheapest = 0;
	if(!(*stack))
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last = last_node(stack);
		last->next = node;
		node->previous = last;
	}
}