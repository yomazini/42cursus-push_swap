/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+        */
/*   Created: 2025/01/20 11:45:27 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/22 15:04:49 by ymazini          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    initialize_stack(t_stack_node **stack, int ac, char **av)
{
    char    **strs;
    int     i;
    long    n;

    while (--ac)
    {
        strs = ft_split(*++av, ' ');
        i = 0;
        while (strs[i])
        {
            if (!handle_str(strs[i]))
                ft_error(stack, strs);
            n = ft_atol1(strs[i++], stack, strs);
            if (n > INT_MAX || n < INT_MIN)
                ft_error(stack, strs);
            append_node(stack, (int)n);
        }
        free_strs(strs);
    }
}

void error(t_stack_node **a, t_stack_node **b, char *line)
{
    free_stack(b);
    free(line);
    ft_error(a, NULL);
}

static void parse_command(t_stack_node **a, t_stack_node **b, char *command)
{
    if (!ft_strncmp(command, "pa\n", 3))
        pa(a, b, 1);  // Changed testing to 1
    else if (!ft_strncmp(command, "pb\n", 3))
        pb(b, a, 1);
    else if (!ft_strncmp(command, "sa\n", 3))
        sa(a, 1);
    else if (!ft_strncmp(command, "sb\n", 3))
        sb(b, 1);
    else if (!ft_strncmp(command, "ss\n", 3))
        ss(a, b, 1);
    else if (!ft_strncmp(command, "ra\n", 3))
        ra(a, 1);
    else if (!ft_strncmp(command, "rb\n", 3))
        rb(b, 1);
    else if (!ft_strncmp(command, "rr\n", 3))
        rr(a, b, 1);
    else if (!ft_strncmp(command, "rra\n", 4))
        rra(a, 1);
    else if (!ft_strncmp(command, "rrb\n", 4))
        rrb(b, 1);
    else if (!ft_strncmp(command, "rrr\n", 4))
        rrr(a, b, 1);
    else
        error(a, b, command);
}

static void init_var(t_stack_node **stack_a, t_stack_node **stack_b, int *len)
{
    *len = 0;
    *stack_a = NULL;
    *stack_b = NULL;
}
int has_duplicates(t_stack_node *stack)
{
    t_stack_node *current;
    t_stack_node *runner;

    current = stack;
    while (current != NULL)
    {
        runner = current->next;
        while (runner != NULL)
        {
            if (current->value == runner->value)
                return (1);
            runner = runner->next;
        }
        current = current->next;
    }
    return (0);
}

int main(int ac, char **av)
{
    t_stack_node  *stack_a;
    t_stack_node  *stack_b;
    int     len;
    char    *next_line;

    if (ac > 1)
    {
        init_var(&stack_a, &stack_b, &len);
        initialize_stack(&stack_a, ac, av);
        if (!stack_a || has_duplicates(stack_a))
            ft_error(&stack_a, NULL);
        len = stack_length(stack_a);
        next_line = get_next_line(0);
        while (next_line)
        {
            parse_command(&stack_a, &stack_b, next_line);
            free(next_line);
            next_line = get_next_line(0);
        }
		if (stack_sorted(stack_a) && stack_b == NULL)
   		 	write(1, "OK\n", 3);
		else
   		 	write(1, "KO\n", 3);
        free_stack(&stack_a);
		free_stack(&stack_b); 
    }
}