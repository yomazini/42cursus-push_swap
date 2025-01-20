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

//push_swap.c
//main function

//parsing folder --

//libft_tools.c
size_t	ft_strlen(const char *s);
int	stack_length(t_stack_node *stack);
t_stack_node	*last_node(t_stack_node *stack);
int	ft_atoi(const char *str);
t_stack_node	*ft_lstnew(void *content);

// split.c file
int	ft_isdigit(int c);
char	**ft_split(char *s, char c);

//---

// validating.c



#endif