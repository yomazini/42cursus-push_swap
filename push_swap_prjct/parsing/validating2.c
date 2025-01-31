/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:30:46 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/31 15:36:12 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
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
        while (temp[j])
        {
            result[k] = ft_strdup(temp[j]);
            if (!result[k])
            {
                free_strs(temp);
                free_strs(result);
                return (NULL);
            }
            k++;
            j++;
        }
        free_strs(temp);
        i++;
    }
    result[k] = NULL;
    return (result);
}
