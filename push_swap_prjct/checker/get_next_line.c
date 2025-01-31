/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:36:07 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/31 21:19:22 by ymazini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			read_size;
	char		temp[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (!gnl_strchr(buf, '\n'))
	{
		read_size = read(fd, temp, BUFFER_SIZE);
		if (read_size < 0)
			return (free(buf), buf = NULL, NULL);
		if (read_size == 0)
			break ;
		temp[read_size] = 0;
		buf = gnl_strjoin(buf, temp);
	}
	if (!buf)
		return (NULL);
	line = gnl_strjoin(NULL, buf);
	if (gnl_strchr(buf, '\n'))
		buf = gnl_strjoin(buf + gnl_strlen(line), NULL);
	else
		free(buf), buf = NULL;
	return (line);
}
