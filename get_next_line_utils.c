/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:52:42 by rihammou          #+#    #+#             */
/*   Updated: 2026/11/12 11:31:37 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *extract_line(char *stash, int size)
{
	char *line;
	int		i;

	i = 0;
	line = malloc(size);
	if (!line)
		return (NULL);
	while (size > 1)
	{
		line[i] = stash[i];
		i++;
		size--;
	}
	line[i] = '\0';
	return (line);
}

char *update_stash(char *str, int size)
{
	char *temp;
	int i;

	i = 0;
	temp = malloc(size + 1);
	if (!temp)
		return (NULL);
	while (size > 0)
	{
		temp[i] = str[i];
		i++;
		size--;
	}
	temp[i] = '\0';
	return (temp);
}

int	has_newline(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char *read_stash(int fd, char *stash, char *buffer)
{
	ssize_t bytes;
	int		i;
	
	i = 0;
	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	while (bytes > 0 && buffer[i] != '\0' && buffer[i] != '\n')
	{
		i++;
		if (buffer[i] == '\0')
		{
			stash = update_stash(buffer, i);
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (!bytes)
				buffer[bytes] = '\0';
		}
		else if (buffer[i] == '\n')
		{
			stash = update_stash(buffer, i);
			return (stash);
		}
	}
}
