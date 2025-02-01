/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*   Created: 2024/11/29 18:18:22 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/20 12:02:05 by ymazini          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char    *ft_strchr(const char *s, int c)
{
    char    *str;

    str = (char *)s;
    while (*str)
    {
        if (*str == (char)c)
            return (str);
        str++;
    }
    if (*str == (char)c)
        return (str);
    return (NULL);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  len1;
    size_t  len2;
    char    *str;

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
