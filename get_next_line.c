/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:32:36 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/29 11:32:50 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*final_line(char **line_buffer)
{
	char	*leftover_data;
	char	*clean_line;
	ssize_t	i;

	i = 0;
	while ((*line_buffer)[i] != '\n' && (*line_buffer)[i] != '\0')
		i++;
	if ((*line_buffer)[i] == 0 || (*line_buffer)[1] == 0)
		return (NULL);
	leftover_data = ft_substr(*line_buffer, i + 1, ft_strlen(*line_buffer) - i);
	if (leftover_data && !*leftover_data)
	{
		free(leftover_data);
		leftover_data = NULL;
	}
	clean_line = ft_substr(*line_buffer, 0, i + 1);
	free(*line_buffer);
	*line_buffer = clean_line;
	return (leftover_data);
}

static char	*catch_the_newline(int fd, char *static_buf, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(static_buf);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		static_buf = ft_strjoin(static_buf, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (static_buf);
}

char	*get_next_line(int fd)
{
	static char	*static_buf;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 \
			|| BUFFER_SIZE > INT_MAX)
	{
		free(static_buf);
		static_buf = NULL;
		return (NULL);
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = catch_the_newline(fd, static_buf, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	static_buf = final_line(&line);
	if (!line)
		return (free(static_buf), NULL);
	return (line);
}
