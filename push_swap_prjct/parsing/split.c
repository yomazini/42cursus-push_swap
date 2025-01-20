/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:32:26 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/20 16:13:09 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	count_words(char *s, char c)
{
	int	count;
	int	inside_word;

	count = 0;
	inside_word = 0;
	while (*s)
	{
		if (*s == c)
			inside_word = 0;
		else if (!inside_word)
		{
			inside_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor)
{
	char	*next_word;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[*cursor] == c)
		(*cursor)++;
	while (s[*cursor + len] != c && s[*cursor + len])
		len++;
	next_word = malloc((len + 1) * sizeof(char));
	if (!next_word)
		return (NULL);
	while (i < len)
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;
	int		cursor;

	i = -1;
	cursor = 0;
	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	result_array = malloc((words_count + 1) * sizeof(char *));
	if (!result_array)
		return (NULL);
	while (++i < words_count)
	{
		result_array[i] = get_next_word(s, c, &cursor);
		if (!result_array[i])
		{
			while (i > 0)
				free(result_array[--i]);
			return (free(result_array), NULL);
		}
	}
	result_array[i] = NULL;
	return (result_array);
}
