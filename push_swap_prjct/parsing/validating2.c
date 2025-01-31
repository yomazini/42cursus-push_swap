/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:30:46 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/31 15:41:44 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
