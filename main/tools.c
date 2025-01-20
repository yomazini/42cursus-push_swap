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

void    ft_putstr(char *str)
{
        while(*str)
        {
                write(1,str,1);
                str++;
        }
}

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

t_stack_node *find_min_node(t_stack_node *stack)
{
	t_stack_node *min_node;
	long min_number;

	min_number = INT_MAX + 987;
	if(!stack)
		return NULL;
	while (stack)
	{
		if (stack->value < min_number)
		{
			min_number = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

//find max in stack

t_stack_node *find_max_node(t_stack_node *stack)
{
	t_stack_node *max_node;
	long max_number;

	max_number = INT_MIN - 6;
	if (!stack)
		return (NULL);
	while(stack)
	{
		if (max_number > stack->value)
		{
			max_number = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}





//TODO: this pomodoro (finish all moves.     <rotate &&  rev_rotate>   < | sa sb ss | ra rb rr | rra rrb rrr | >)

void	ft_swap_node(t_stack_node **head)
{
	t_stack_node *tmp;
	t_stack_node *prev_1;
	t_stack_node *next_1;

	if (!(*head) || !((*head)->next))
		return ;

	tmp = *head;
	prev_1 = (*head)->previous;
	next_1 = (*head)->next->next;

	(*head) = (*head)->next; // Update head to point to the second node
	(*head)->next = tmp; // Update new head's next to point to the old head
	(*head)->previous = prev_1; // Update new head's prev to point to the old head's prev

	tmp->next = next_1; // Update old head's next to point to next_1
	tmp->previous = *head; // Update old head's prev to point to the new head

	if (next_1) // Update next_1's previous pointer if it exists
		next_1->previous = tmp;
	if (prev_1) // Update prev_1's next pointer if it exists
		prev_1->next = *head;
}


void	min_on_top(t_stack_node **a)
{
	while((*a)->value != find_min_node((*a)->value))
	{
		if (find_min_node(*a)->above_median_line)
			ra(a, 0);
		else
			rra(a, 0);
	}
}

void	ft_rotate_node(t_stack_node **head)
{
	t_stack_node *last;
	if (!*head || !(*head)->next)
		return ;
	last = last_node(head);
	last->next = (*head);
	(*head) = (*head)->next;
	(*head)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
}

void	ft_rev_rotate_node(t_stack_node **head)
{
	t_stack_node *last;
	if (!*head || !(*head)->next)
		return;
	last = last_node(head);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = (*head);
	(*head) = last;
	last->next->previous = last;
}

//finish all sa sb ss
void	sa(t_stack_node **a, int testing)
{
	ft_swap_node(a);
	if (!testing)
		ft_putstr("sa\n");
}

void	sb(t_stack_node **b, int testing)
{
	ft_swap_node(b);
	if (!testing)
		ft_putstr("sa\n");
}

void	ss(t_stack_node **a, t_stack_node **b,int testing)
{

	ft_swap_node(a);
	ft_swap_node(b);
	if (!testing)
		ft_putstr("ss\n");
}

/*
rotate fun 
*/


void	ra(t_stack_node **a, int testing)
{
	ft_rotate_node(*a);
	if(!testing)
		ft_putstr("ra\n");

}

void	rb(t_stack_node **b, int testing)
{
	ft_rotate_node(*b);
	if(!testing)
		ft_putstr("rb\n");
}

void	rr(t_stack_node **a, int testing)
{
	ft_rotate_node(*a);
	ft_rotate_node(*b);
	if(!testing)
		ft_putstr("rr\n");
}

/*
rev rotate fun
*/

void	rra(t_stack_node **a, int testing)
{
	ft_rev_rotate_node(*a);
	if(!testing)
		ft_putstr("rra\n");
}

void	rrb(t_stack_node **b, int testing)
{
	ft_rev_rotate_node(*b);
	if(!testing)
		ft_putstr("rrb\n");

}

void	rrr(t_stack_node **a, t_stack_node **b, int testing)
{
	ft_rev_rotate_node(*a);
	ft_rev_rotate_node(*b);
	if(!testing)
		ft_putstr("rrr\n");
}


/*
		--> Split here move from the libft with edition and put it here as well;
		--> 
*/

//sort 3 in stack

void	sort_three(t_stack_node **a) // our goal to move biggest to botthom in first two condition
{
	t_stack_node *biggest;
	biggest = find_max_node(a);
	if (biggest == (*a))
		ra(*a, 0);
	else if (biggest == (*a)->next)
		rra(*a, 0);
	if ((*a)->value > (*a)->next->value)
		sa(*a, 0);
}


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
/*
	define two functions pb && pa && push function
*/

void	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node *push_node;
	if (!(*src))
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	push_node->previous = NULL;

	if (!(*dst))
	{
		(*dst) = push_node;
		(*dst)->next = NULL;
	}
	else
	{
		push_node->next = (*dst);
		push_node->next->previous = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, int testing)
{
	push(a,b);
	if (!testing)
		ft_putstr("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, int testing)
{
	push(b,a);
	if (!testing)
		ft_putstr("pb\n");
}

/*
	*-------------------*  *----------------------*  *----------------------*
*/

// now all the functions of the Turk algo 

// I/ init_a_to_b functions {2Pomodoro}


/*
	void	init_nodes_a(t_stack_node *a, t_stack_node *b) //Define a function that combines all the functions needed to prepare stack `a`, ready for our pushing and sorting. These functions set the data inside the node's structure

	{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
	}

	finish also settarget b; 
*/

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int len;

	len = len_stack(a);
	if (len-- > 3 && !stack_sorted(a))
		pb(a,b,0);
	if (len-- > 3 && !stack_sorted(a))
		pb(a,b,0);
	while (len-- && !stack_sorted(a))
	{
		init_node_a(a, b);
		move_a_2_b(a,b);
	}
	sort_three(a);
	while(*b)
	{
		init_node_b(a,b);
		move_b_2_a(a,b);
	}
	curreent_position(a);
	move_min_to_top(a);
}
void	init_node_a(a, b)
{
	currrent_index(a);
	currrent_index(b);
	set_target_a(a,b);
	cost_analysis_a(a,b);
	set_cheapest(a);
}



// current_index | set_target_a | cost_analysis_a | set_cheapest | 

void	current_index(t_stack_node *stack)
{
	int i;
	int median;

	i = 0;
	median = len_stack(stack)/2;
	while(stack)
	{
		stack->indexing = i;
		if (!stack)
			return;
		if (i <= median)
			stack->above_median_line = 1;
		else
			stack->above_median_line = 0;
		stack = stack->next;
		i++;
	}
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node *current_b;
	t_stack_node *target_node;
	long best_match_index;

	while(a)
	{
		best_match_index = LONG_MAX;
		current_b = b;
		while (current_b)
		{
			if (a->value > current_b->value && current_b->value > best_match_index)	
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MAX)
			a->target_node = find_max_node(b);
		else
			a->target_node = target_node;
		a = a -> next;
	}
}

void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int len_a;
	int len_b;

	len_a = len_stack(a);
	len_b = len_stack(b);
	while(a)
	{
		a->push_cost = a->indexing;
		if(!(a->above_median_line))
			a->push_cost = len_a - (a->push_cost);
		if (a->target_node->above_median_line)
			a->push_cost = a->push_cost + a->target_node->indexing;
		else
			a->push_cost = a->push_cost + len_b - (a->target_node->indexing);
		a = a->indexing;
	}
}
void	set_cheapest_node(t_stack_node *stack)
{
	t_stack_node *cheapest_node;
	long cheapest_value;

	cheapest_node = stack;
	if (!stack )
		return;
	cheapest_value = LONG_MAX;
	while(stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_node = stack;
			cheapest_value = stack->push_cost;
		}
		stack = stack->next; 
	}
	cheapest_node->cheapest = 1;
}


void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node *target_node;
	t_stack_node *current_a;
	long best_match_index;

	best_match_index = LONG_MAX;

	while(b)
	{
		while(current_a)
		{
			if(current_a->value < b->value && current_a->value < best_match_index)
			{
				best_match_index = current_a->next;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min_node(a);
		else
			b->target_node = target_node;

		b = b->next;
	}
}

t_stack_node *get_chepest(t_stack_node *stack)
{
	if (!stack)
		return NULL;
	while(stack)
	{
		if(stack->cheapest)
			return stack;
		stack = stack->next;
	}
	return NULL;
}


/*
*/

void	rotate_a_n_b(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while ((cheapest_node->target_node != (*b) && (*a) != cheapest_node)
		rr(a, b, 0);
	current_index(*a);
	current_index(*b);
}


void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char which_stack)
{
	
	while(*stack != top_node)
	{
		if (which_stack == 'a')
		{
			if (top_node->above_median_line)
				ra(stack,0);
			else
				rra(stack,0);
		}
		else if (which_stack == 'b')
		{
			if (top_node->above_median_line)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}

}
