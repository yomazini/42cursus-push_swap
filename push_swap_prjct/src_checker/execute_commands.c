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

void	error(t_stack_node **a, t_stack_node **b, char *line)
{
	free_stack(b);
	free(line);
	ft_error(a, NULL);
}
