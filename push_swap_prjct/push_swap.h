#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <limits.h>
//Must delete this
#include <stdio.h>
// # include <fcntl.h>


typedef struct s_stack_node
{
	int		indexing;
	int		value;
	int		push_cost;
	int		above_median_line;
	int		cheapest;
	struct s_stack_node *previous;
	struct s_stack_node *next;
	struct s_stack_node	*target_node;
}	t_stack_node;




#endif