/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools_4checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+        */
/*   Created: 2025/02/01 17:42:32 by ymazini           #+#    #+#             */
/*   Updated: 2025/02/01 17:42:32 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int  count_words(const char *str, char c)
{
    int i;
    int counter;

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

static int  check_str(char **strs, int index)
{
    int k;

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

static char **sp_strs(char **strs, const char *s, char c)
{
    size_t          i;
    size_t          j;
    size_t          count;

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

char    **ft_split(char const *s, char c)
{
    char    **strs;

    if (!s)
        return (NULL);
    strs = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!strs)
        return (NULL);
    strs = sp_strs(strs, s, c);
    return (strs);
}
/*

In this section, we'll evaluate the checker's ability to manage a list of instructions
that sort the list. Execute the following 2 tests. If at least one fails, no points will be
awarded for this section. Move to the next one. Don't forget to press CTRLD to
stop reading during the instruction phase.
Run checker with the following command "$./checker 0 1 2" then press CTRLD
without writing any instruction. The program should display "OK".
Run checker with the following command "$./checker 0 9 1 8 2" then write the
following valid action list "[pb, ra, pb, ra, sa, ra, pa, pa]". The program should
display "OK".
Run checker with a valid list as parameter of your choice then write a valid
instruction list that order the integers. Checker must display "OK". You'll have to
specifically check that the program wasn't developed to only answer correctly on
the test included in this scale. You should repeat this test couple of times with
several permutations before you validate it
*/
int handle_str(const char *str)
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

void    ft_error(t_stack_node **stack, char **strs)
{
    write(2, "Error\n", 6);  // Changed from write(1, ...) to write(2, ...)
    free_stack(stack);
    free_strs(strs);
    exit(0);
}

long    ft_atol1(const char *str, t_stack_node **stack, char **strs)
{
    long    num;
    int     counter;
    int     signe;
    int     start;

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

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t  i;

    i = 0;
    if (n == 0)
        return (0);
    while (s1[i] && s2[i] && s1 [i] == s2[i] && i < n)
    {
        i++;
    }
    if (i == n)
        return (0);
    return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}