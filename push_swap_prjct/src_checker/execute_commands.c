/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+        */
/*   Created: 2025/01/20 12:00:03 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/20 12:07:02 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Function to execute commands (already included in checker.c)
// Just ensure the function signatures and implementations are correct

void    execute_command(t_stack_node **a, t_stack_node **b, char *command)
{
    if (!ft_strncmp(command, "pa\n", 3))
        pa(a, b, 0);
    else if (!ft_strncmp(command, "pb\n", 3))
        pb(b, a, 0);
    else if (!ft_strncmp(command, "sa\n", 3))
        sa(a, 0);
    else if (!ft_strncmp(command, "sb\n", 3))
        sb(b, 0);
    else if (!ft_strncmp(command, "ss\n", 3))
        ss(a, b, 0);
    else if (!ft_strncmp(command, "ra\n", 3))
        ra(a, 0);
    else if (!ft_strncmp(command, "rb\n", 3))
        rb(b, 0);
    else if (!ft_strncmp(command, "rr\n", 3))
        rr(a, b, 0);
    else if (!ft_strncmp(command, "rra\n", 4))
        rra(a, 0);
    else if (!ft_strncmp(command, "rrb\n", 4))
        rrb(b, 0);
    else if (!ft_strncmp(command, "rrr\n", 4))
        rrr(a, b, 0);
    else
        error(a, b, command);
}