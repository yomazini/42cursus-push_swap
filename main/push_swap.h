/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:09:05 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/16 21:45:55 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// this is the first the header and what function will use

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#ifdef	BUFFER_SIZE	
#define	BUFFER_SIZE	
#endif

#include "libft/libft.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
# include <fcntl.h>

// t_list here for boolan i will change it to int and only will get (1 || 0);

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

// those are the function will be helping me

// those are the functions will be parsing & validating 

// those are the moves

// those are the function for sort 3 in stack STACK OF 3

// split and join 

// stack creation 
void	stack_initilize(t_stack_node **a, char **av, int second_ac);
void	initilize_nodes(t_stack_node *a, t_stack_node *b);
void	curreent_position();

#endif