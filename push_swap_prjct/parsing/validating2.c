/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:30:46 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/31 16:21:28 by ymazini          ###   ########.fr       */
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

// static int	count_total_words(int ac, char **av)
// {
// 	int		total;
// 	int		i;
// 	char	**temp;

// 	total = 0;
// 	i = 1;
// 	while (i < ac)
// 	{
// 		temp = split(av[i], ' ');
// 		if (!temp)
// 			return (-1);
// 		total += ft_strslen(temp);
// 		free_strs(temp);
// 		i++;
// 	}
// 	return (total);
// }

// static void	init_var_4_split_args(int *k, int *i)
// {
// 	*k = -1;
// 	*i = 0;
// }

// char	**split_args(int ac, char **av)
// {
// 	char	**result;
// 	char	**temp;
// 	int		i;
// 	int		j;
// 	int		k;

// 	result = malloc(sizeof(char *) * (count_total_words(ac, av) + 1));
// 	if (!result)
// 		return (NULL);
// 	init_var_4_split_args(&k, &i);
// 	while (++i < ac)
// 	{
// 		temp = split(av[i], ' ');
// 		if (!temp)
// 			return (free_strs(result), NULL);
// 		j = -1;
// 		while (temp[++j])
// 		{
// 			result[++k] = ft_strdup(temp[j]);
// 			if (!result[k])
// 				return (free_strs(temp), free_strs(result), NULL);
// 		}
// 		free_strs(temp);
// 	}
// 	return (result[k] = NULL, result);
// }

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

static int	copy_temp(char **result, char **temp, int k)
{
	int	j;

	j = 0;
	while (temp[j])
	{
		result[k] = ft_strdup(temp[j]);
		if (!result[k])
		{
			free_strs(temp);
			free_strs(result);
			return (-1);
		}
		k++;
		j++;
	}
	return (k);
}

char	**split_args(int ac, char **av)
{
	char	**result;
	char	**temp;
	int		i;
	int		k;
	int		total_words;

	total_words = count_total_words(ac, av);
	if (total_words == -1)
		return (NULL);
	result = malloc(sizeof(char *) * (total_words + 1));
	if (!result)
		return (NULL);
	k = 0;
	i = 0;
	while (++i < ac)
	{
		temp = split(av[i], ' ');
		if (!temp)
			return (free_strs(result), NULL);
		k = copy_temp(result, temp, k);
		free_strs(temp);
		if (k == -1)
			return (NULL);
	}
	return (result[k] = NULL, result);
}
