/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:32:26 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/31 15:28:50 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words(char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*extract_word(char *s, char c, int *index)
{
	int		start;
	int		end;
	char	*word;

	while (s[*index] == c)
		(*index)++;
	start = *index;
	while (s[*index] && s[*index] != c)
		(*index)++;
	end = *index;
	if (start == end)
		return (NULL);
	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[start], end - start + 1);
	return (word);
}

static void	init_vars_4_split(int *i, int *j)
{
	*i = 0;
	*j = -1;
}

char	**split(char *s, char c)
{
	int		word_count;
	char	**result;
	int		i;
	int		j;

	if (!s || !*s)
		return (NULL);
	word_count = count_words(s, c);
	init_vars_4_split(&i, &j);
	if (!word_count)
		return (NULL);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	while (++j < word_count)
	{
		result[j] = extract_word(s, c, &i);
		if (!result[j])
		{
			while (j-- > 0)
				free(result[j]);
			return (free(result), NULL);
		}
	}
	return (result[j] = NULL, result);
}
