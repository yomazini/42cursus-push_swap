/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:18:56 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/31 22:09:43 by ymazini          ###   ########.fr       */
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
	const char	*cmds[] = {"pa", "pb", "sa", "sb", "ss",
		"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};
	int			i;
	size_t		cmd_len;

	cmd_len = ft_strlen(cmd);
	if (cmd_len > 0 && cmd[cmd_len - 1] == '\n')
		cmd[cmd_len - 1] = '\0';

	i = -1;
	while (cmds[++i])
	{
		if (ft_strcmp(cmd, (char *)cmds[i]) == 0)
			return (1);
	}
	return (0);
}

int	execute(char *cmd, t_stack_node **a, t_stack_node **b)
{
	size_t	len = ft_strlen(cmd);
	if (len > 0 && cmd[len - 1] == '\n')
		cmd[len - 1] = '\0';

	if (ft_strcmp(cmd, "pa") == 0) return (pa(a, b, 1), 1);
	if (ft_strcmp(cmd, "pb") == 0) return (pb(b, a, 1), 1);
	if (ft_strcmp(cmd, "sa") == 0) return (sa(a, 1), 1);
	if (ft_strcmp(cmd, "sb") == 0) return (sb(b, 1), 1);
	if (ft_strcmp(cmd, "ss") == 0) return (ss(a, b, 1), 1);
	if (ft_strcmp(cmd, "ra") == 0) return (ra(a, 1), 1);
	if (ft_strcmp(cmd, "rb") == 0) return (rb(b, 1), 1);
	if (ft_strcmp(cmd, "rr") == 0) return (rr(a, b, 1), 1);
	if (ft_strcmp(cmd, "rra") == 0) return (rra(a, 1), 1);
	if (ft_strcmp(cmd, "rrb") == 0) return (rrb(b, 1), 1);
	if (ft_strcmp(cmd, "rrr") == 0) return (rrr(a, b, 1), 1);
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
		// Skip empty lines or lines with only a newline
		if (cmd[0] == '\0' || (cmd[0] == '\n' && cmd[1] == '\0'))
		{
			free(cmd);
			cmd = get_next_line(0);
			continue;
		}
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
