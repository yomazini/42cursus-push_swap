#include <stdlib.h>
#include "push_swap.h"

// Helper function to count the number of words in the string
static int	count_words(char *s, char c)
{
	int	count = 0;
	int	inside_word = 0;

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

// Helper function to extract the next word
static char	*get_next_word(char *s, char c, int *cursor)
{
	char	*next_word;
	int		len = 0;
	int		i = 0;

	while (s[*cursor] == c) // Skip delimiters
		(*cursor)++;
	while (s[*cursor + len] != c && s[*cursor + len]) // Count word length
		len++;
	next_word = malloc((len + 1) * sizeof(char)); // Allocate memory for the word
	if (!next_word)
		return (NULL);
	while (i < len) // Copy the word into the allocated space
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0'; // Null-terminate the string
	return (next_word);
}

// Split the string into an array of words
char	**ft_split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i = 0;
	int		cursor = 0;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	result_array = malloc((words_count + 1) * sizeof(char *)); // Allocate array for words
	if (!result_array)
		return (NULL);
	while (i < words_count)
	{
		result_array[i] = get_next_word(s, c, &cursor); // Pass the cursor by reference
		if (!result_array[i])
		{
			// Free allocated memory on error
			while (i > 0)
				free(result_array[--i]);
			free(result_array);
			return (NULL);
		}
		i++;
	}
	result_array[i] = NULL; // Null-terminate the array
	return (result_array);
}