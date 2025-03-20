/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:23:55 by levincen          #+#    #+#             */
/*   Updated: 2025/03/20 18:17:44 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	malloc_temp(int fd, char **temp)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	*temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*temp)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	char		*line;
	int			bytes_read;

	if (malloc_temp(fd, &temp) == 0)
		return (NULL);
	while (!ftt_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(temp);
			if (bytes_read == 0)
				break ;
			return (NULL);
		}
		temp[bytes_read] = '\0';
		buffer = ftt_strjoin(buffer, temp);
	}
	if (ftt_strchr(buffer, '\n'))
		free(temp);
	line = search_copy(buffer);
	buffer = rm_start(buffer, line);
	return (line);
}
