/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools_4checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:21:26 by ymazini           #+#    #+#             */
/*   Updated: 2025/02/01 22:44:23 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			counter++;
		while (str[i] != c && str[i])
			i++;
	}
	return (counter);
}

static int	check_str(char **strs, int index)
{
	int	k;

	if (!strs[index])
	{
		k = 0;
		while (k < index)
			free(strs[k++]);
		free(strs);
		return (0);
	}
	return (1);
}

static char	**sp_strs(char **strs, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			count++;
			(i)++;
		}
		if (count)
		{
			strs[j] = ft_substr(s, i - count, count);
			if (!check_str(strs, j++))
				return (NULL);
		}
	}
	strs[j] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!strs)
		return (NULL);
	strs = sp_strs(strs, s, c);
	return (strs);
}

int	handle_str(const char *str)
{
	if (!*str)
		return (0);
	if ((*str == '-' || *str == '+') && ft_isdigit(*(str + 1)))
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
