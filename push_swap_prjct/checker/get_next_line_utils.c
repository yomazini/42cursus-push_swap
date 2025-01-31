/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:36:10 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/31 21:19:48 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	gnl_strchr(char *s, char c)
{
	int	i;

	i = -1;
	while (s && s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	new = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!new)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		new[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		new[i++] = s2[j++];
	new[i] = 0;
	free(s1);
	return (new);
}
