/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:52:42 by rihammou          #+#    #+#             */
/*   Updated: 2026/11/12 18:24:14 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash, int size)
{
	char	*line;
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

char	*update_stash(char *stash, int size)
{
	char	*temp;
	int		i;
	int		j;

	i = size;
	j = 0;
	while (stash[i])
		i++;
	if (i == size)
	{
		free(stash);
		return (NULL);
	}
	temp = malloc(i - size + 1);
	if (temp)
	{
		while (stash[size])
			temp[j++] = stash[size++];
		temp[j] = '\0';
	}
	free(stash);
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

char	*append_stash(char *stash, char *buffer, char *temp, int len)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (stash)
		while (stash[len])
			len++;
	while (buffer[i])
		i++;
	temp = malloc(len + i + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp[i] = stash[i];
		i++;
	}
	while (buffer[j])
		temp[i++] = buffer[j++];
	temp[i] = '\0';
	free(stash);
	return (temp);
}

char	*read_stash(int fd, char *stash, char *buffer)
{
	ssize_t	bytes;
	char	*temp;

	bytes = 1;
	while (bytes > 0 && !has_newline(stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			return (NULL);
		}
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			temp = append_stash(stash, buffer, NULL, 0);
			if (!temp)
			{
				free(stash);
				return (NULL);
			}
			stash = temp;
		}
	}
	return (stash);
}
