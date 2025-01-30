/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:19:21 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/30 20:35:32 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	syntax_error(char *str_n)
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_error(t_stack_node **a)
{
	free_stack(a);
	ft_putstr("Error\n");
	exit(1);
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (slen);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*s;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	ptr = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*str;

	size = ft_strlen(src);
	str = malloc (size + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, src, size);
	str [size] = '\0';
	return (str);
}

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

static int	count_total_words(int ac, char **av)
{
	int		total;
	int		i;
	char	**temp;

	total = 0;
	i = 1;
	while (i < ac)
	{
		temp = split(av[i], ' ');
		if (!temp)
			return (-1);
		total += ft_strslen(temp);
		free_strs(temp);
		i++;
	}
	return (total);
}

char	**split_args(int ac, char **av)
{
	char	**result;
	char	**temp;
	int		i;
	int		j;
	int		k;

	result = malloc(sizeof(char *) * (count_total_words(ac, av) + 1));
	if (!result)
		return (NULL);
	k = 0;
	i = 1;
	while (i < ac)
	{
		temp = split(av[i], ' ');
		if (!temp)
		{
			free_strs(result);
			return (NULL);
		}
		j = 0;
		// while (temp[j])
		// 	result[k++] = ft_strdup(temp[j++]);
		// free_strs(temp);
		while (temp[j])
		{
    		result[k] = ft_strdup(temp[j]);
    		if (!result[k])
    		{
    		    free_strs(temp);   // Free temp array
    		    free_strs(result); // Free result array
    		    return (NULL);
    		}
    		k++;
    		j++;
		}
		i++;
	}
	result[k] = NULL;
	return (result);
}