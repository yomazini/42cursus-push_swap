/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:22:28 by ymazini           #+#    #+#             */
/*   Updated: 2025/02/01 22:47:41 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int		handle_str(const char *str);
void	ft_error(t_stack_node **stack, char **strs);
long	ft_atol1(const char *str, t_stack_node **stack, char **strs);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	error(t_stack_node **a, t_stack_node **b, char *line);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		has_duplicates(t_stack_node *stack);
void	initialize_stack(t_stack_node **stack, int ac, char **av);

#endif
