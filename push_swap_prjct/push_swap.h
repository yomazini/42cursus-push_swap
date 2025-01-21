/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:52:41 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/21 21:01:01 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
//Must delete this
# include <stdio.h>
// # include <fcntl.h>

typedef struct s_stack_node
{
	int						indexing;
	int						value;
	int						push_cost;
	int						above_median_line;
	int						cheapest;
	struct s_stack_node		*previous;
	struct s_stack_node		*next;
	struct s_stack_node		*target_node;
}	t_stack_node;

//libft_tools.c

int				ft_strlen(const char *s);
int				stack_length(t_stack_node *stack);
t_stack_node	*last_node(t_stack_node *stack);
int				ft_atoi(const char *str);
//t_stack_node	*ft_lstnew(void *content);

// split.c file
int				ft_isdigit(int c);
char			**split(char *s, char c)
;void			free_error(t_stack_node **a);
void			free_stack(t_stack_node **stack);
long ft_atol(const char *s, t_stack_node **a);
//---
// validating.c

int				syntax_error(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
// moves foldder

void			push(t_stack_node **dst, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b, int testing);
void			pb(t_stack_node **a, t_stack_node **b, int testing);
void			ft_rotate_node(t_stack_node **stack);
void			ra(t_stack_node **a, int testing);
void			rb(t_stack_node **b, int testing);
void			rr(t_stack_node **a, t_stack_node **b, int testing);
void ft_rev_rotate_node(t_stack_node **stack);
void			rra(t_stack_node **a, int testing);
void			rrb(t_stack_node **b, int testing);
void			rrr(t_stack_node **a, t_stack_node **b, int testing);
void			ft_swap_node(t_stack_node **head);
void			sa(t_stack_node **a, int testing);
void			sb(t_stack_node **b, int testing);
void			ss(t_stack_node **a, t_stack_node **b, int testing);

// initialiase_a_2_b.c

void			set_cheapest_node(t_stack_node *stack);
void			cost_analysis_a(t_stack_node *a, t_stack_node *b);
void			set_target_a(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void	init_node_a(t_stack_node *a, t_stack_node *b);
t_stack_node	*get_cheapest(t_stack_node *stack);
// initialiase_b_2_a.c
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			set_target_b(t_stack_node *a, t_stack_node *b);

// stackhelper.c
void			ft_putstr(char *str);
int				len_stack(t_stack_node *stack);
int				stack_sorted(t_stack_node *stack);
t_stack_node	*find_min_node(t_stack_node *stack);
t_stack_node	*find_max_node(t_stack_node *stack);

// stackhelper2.c

void			append_node(t_stack_node **stack, int n);
void			init_stack_a(t_stack_node **a, char **av);
void			set_cheapest_node(t_stack_node *stack);

//turk algo

void			min_on_top(t_stack_node **a);
void			sort_three(t_stack_node **a);
void			rotate_a_n_b(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			rev_rotate_a_n_b(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			turk_sort(t_stack_node **a, t_stack_node **b);
void			move_a_2_b(t_stack_node **a, t_stack_node **b);
void			move_b_2_a(t_stack_node **a, t_stack_node **b);
void	prep_for_push(t_stack_node **stack,t_stack_node *top_node,char stack_name);

#endif