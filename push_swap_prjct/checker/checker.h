/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:38:41 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/31 21:20:35 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../push_swap.h"

# define BUFFER_SIZE 42

// Checker main
void	checker(t_stack_node **a, t_stack_node **b);

// Command execution
void	execute_commands(t_stack_node **a, t_stack_node **b);
int		execute(char *cmd, t_stack_node **a, t_stack_node **b);

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strcmp(char *s1, char *s2);

// GNL
char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char *s2);
int		gnl_strchr(char *s, char c);
size_t	gnl_strlen(char *s);

#endif
