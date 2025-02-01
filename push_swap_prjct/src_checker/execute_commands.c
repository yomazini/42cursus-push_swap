/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:22:21 by ymazini          #+#    #+#             */
/*   Updated: 2025/02/01 22:30:05 by ymazini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	ft_atol1(const char *str, t_stack_node **stack, char **strs)
{
	long	num;
	int		counter;
	int		signe;
	int		start;

	counter = 0;
	num = 0;
	signe = 1;
	while ((str[counter] <= 13 && str[counter] >= 9) || str[counter] == ' ')
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter++] == '-')
			signe *= -1;
	}
	start = counter;
	while (ft_isdigit(str[counter]))
		num = num * 10 + (str[counter++] - '0');
	if (counter - start > 10)
		ft_error(stack, strs);
	return (signe * num);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = 0;
	len2 = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2 + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
		ptr[j++] = s[i++];
	ptr[j] = '\0';
	return (ptr);
}

void	execute_command(t_stack_node **a, t_stack_node **b, char *command)
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

void	error(t_stack_node **a, t_stack_node **b, char *line)
{
	free_stack(b);
	free(line);
	ft_error(a, NULL);
}
