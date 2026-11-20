/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:37:45 by rihammou          #+#    #+#             */
/*   Updated: 2026/11/20 17:42:30 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_str(char *str)
{
	int	size;

	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	if (str[size] == '\n')
		size++;
	return (size);
}

int	error_handle(char *c, char **str)
{
	if (!c)
	{
		free(*str);
		*str = NULL;
		return (0);
	}
	return (1);
}

char	*extract_line(char *str, int size)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(size);
	if (!line)
		return (NULL);
	while (size > 1)
	{
		line[i] = str[i];
		i++;
		size--;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!error_handle(buffer, &str))
		return (NULL);
	str = read_line(fd, str, buffer, 1);
	free(buffer);
	if (!str)
		return (NULL);
	line = extract_line(str, len_str(str) + 1);
	if (!error_handle(line, &str))
		return (NULL);
	str = update_line(str, len_str(str));
	return (line);
}
