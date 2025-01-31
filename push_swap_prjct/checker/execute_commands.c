/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:18:56 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/31 21:19:00 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i] && s1[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] -(unsigned char)s2[i]);
}

static int	is_valid(char *cmd)
{
	const char	*cmds[] = {"pa\n", "pb\n", "sa\n", "sb\n", "ss\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", NULL};
	int			i;

	i = -1;
	while (cmds[++i])
		if (!ft_strncmp(cmd, cmds[i], ft_strlen(cmds[i])))
			return (1);
	return (0);
}

int	execute(char *cmd, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strcmp(cmd, "pa\n")) return (pa(a, b, 1), 1);
	if (!ft_strcmp(cmd, "pb\n")) return (pb(b, a, 1), 1);
	if (!ft_strcmp(cmd, "sa\n")) return (sa(a, 1), 1);
	if (!ft_strcmp(cmd, "sb\n")) return (sb(b, 1), 1);
	if (!ft_strcmp(cmd, "ss\n")) return (ss(a, b, 1), 1);
	if (!ft_strcmp(cmd, "ra\n")) return (ra(a, 1), 1);
	if (!ft_strcmp(cmd, "rb\n")) return (rb(b, 1), 1);
	if (!ft_strcmp(cmd, "rr\n")) return (rr(a, b, 1), 1);
	if (!ft_strcmp(cmd, "rra\n")) return (rra(a, 1), 1);
	if (!ft_strcmp(cmd, "rrb\n")) return (rrb(b, 1), 1);
	if (!ft_strcmp(cmd, "rrr\n")) return (rrr(a, b, 1), 1);
	return (0);
}

static void	clean_and_exit(t_stack_node **a, t_stack_node **b, int status)
{
	free_stack(a);
	free_stack(b);
	if (status == 1)
		ft_putstr("Error\n");
	exit(status);
}

void	execute_commands(t_stack_node **a, t_stack_node **b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (!is_valid(cmd) || !execute(cmd, a, b))
		{
			free(cmd);
			clean_and_exit(a, b, 1);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	free(cmd);
}
