/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:52:42 by rihammou          #+#    #+#             */
/*   Updated: 2026/11/16 13:54:36 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*update_line(char *str, int size)
{
	char	*temp;
	int		i;
	int		j;

	i = size;
	j = 0;
	while (str[i])
		i++;
	if (i == size)
	{
		free(str);
		return (NULL);
	}
	temp = malloc(i - size + 1);
	if (!temp)
	{
		free (str);
		return (NULL);
	}
	while (str[size])
		temp[j++] = str[size++];
	temp[j] = '\0';
	free(str);
	return (temp);
}

int	has_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*append_line(char *str, char *buffer, char *temp, int len)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (str)
		while (str[len])
			len++;
	while (buffer[i])
		i++;
	temp = malloc(len + i + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp[i] = str[i];
		i++;
	}
	while (buffer[j])
		temp[i++] = buffer[j++];
	temp[i] = '\0';
	free(str);
	return (temp);
}

char	*read_line(int fd, char *str, char *buffer)
{
	int	bytes;

	bytes = 1;
	while (bytes > 0 && !has_newline(str))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(str);
			return (NULL);
		}
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			str = append_line(str, buffer, NULL, 0);
			if (!str)
			{
				free(str);
				return (NULL);
			}
		}
	}
	return (str);
}
