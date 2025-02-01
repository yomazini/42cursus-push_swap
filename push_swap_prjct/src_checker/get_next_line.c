/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+        */
/*   Created: 2024/11/29 18:18:22 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/20 12:02:05 by ymazini          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    clear_pointer(char **str)
{
    if (!*str)
        return ;
    free(*str);
    *str = NULL;
}

char    *get_currentline(char *str)
{
    int     i;
    char    *line;
    int     j;

    j = 0;
    i = 0;
    if (!str)
        return (NULL);
    while (str[i] != '\n' && str[i])
        i++;
    if (str[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (!line)
        return (NULL);
    while (j < i)
        line[j++] = *str++;
    line[j] = '\0';
    return (line);
}

static char *get_remainder(char *str)
{
    char    *remainder;
    char    *newline;

    if (!str || !*str)
        return (free(str), NULL);
    newline = ft_strchr(str, '\n');
    if (!newline)
    {
        clear_pointer(&str);
        return (NULL);
    }
    remainder = ft_strdup(newline + 1);
    if (!remainder)
        return (clear_pointer(&str), NULL);
    clear_pointer(&str);
    return (remainder);
}

char    *fill_remainder(char *rem, char *buffer)
{
    char    *temp;

    temp = rem;
    rem = ft_strjoin(rem, buffer);
    if (!rem)
    {
        clear_pointer(&temp);
        return (NULL);
    }
    clear_pointer(&temp);
    return (rem);
}

char    *get_next_line(int fd)
{
    static char *rem;
    char        *buffer;
    ssize_t     bytes;
    char        *line;

    buffer = malloc((size_t)BUFFER_SIZE + 1);
    if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > (size_t)-1 || !buffer)
        return (clear_pointer(&buffer), clear_pointer(&rem), NULL);
    while (1)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes <= 0)
            break ;
        buffer[bytes] = '\0';
        rem = fill_remainder(rem, buffer);
        if (!rem || ft_strchr(rem, '\n'))
            break ;
    }
    if (!rem || !*rem || bytes < 0)
        return (clear_pointer(&buffer), clear_pointer(&rem), NULL);
    line = get_currentline(rem);
    if (!line)
        return (clear_pointer(&buffer), clear_pointer(&rem), NULL);
    rem = get_remainder(rem);
    return (clear_pointer(&buffer), line);
}