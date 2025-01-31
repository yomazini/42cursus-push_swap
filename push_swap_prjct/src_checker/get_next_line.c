/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymazini <ymazini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:36:07 by ymazini           #+#    #+#             */
/*   Updated: 2025/01/31 21:40:54 by ymazini          ###   ########.fr       */
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

	// Read from the file descriptor until a newline is found
	while (!gnl_strchr(buf, '\n'))
	{
		read_size = read(fd, temp, BUFFER_SIZE);
		if (read_size < 0)
			return (free(buf), buf = NULL, NULL); // Free buffer on read error
		if (read_size == 0)
			break ; // End of file
		temp[read_size] = 0;
		buf = gnl_strjoin(buf, temp); // Append new data to the buffer
	}

	if (!buf)
		return (NULL); // No data to process

	// Extract the line up to the newline
	line = gnl_strjoin(NULL, buf);
	if (!line)
		return (free(buf), buf = NULL, NULL); // Free buffer on allocation failure

	// Update the buffer to remove the extracted line
	if (gnl_strchr(buf, '\n'))
	{
		char *new_buf = gnl_strjoin(NULL, buf + gnl_strlen(line));
		free(buf); // Free the old buffer
		buf = new_buf; // Update the buffer with the remaining content
	}
	else
	{
		free(buf); // Free the buffer if no more lines are left
		buf = NULL;
	}

	return (line);
}