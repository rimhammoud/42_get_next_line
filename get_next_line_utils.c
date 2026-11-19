/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:52:42 by rihammou          #+#    #+#             */
/*   Updated: 2026/11/19 12:54:42 by rihammou         ###   ########.fr       */
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
	int	i;

	i = 0;
	while(str[size])
	{
		str[i] = str[size];
		i++;
		size++;
	}
	str[i] = '\0';
	if (i == 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
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

char	*append_line(char *str, char *buffer, char *temp, size_t len)
{
	size_t				i;
	size_t				j;
	static size_t		cap;

	j = 0;
	i = 0;
	if (!str)
		cap = 0;
	if (str)
		while (str[len])
			len++;
	while (buffer[i])
		i++;
	temp = str;
	if (len + i + 1 > cap)
	{
		if (cap == 0)
			cap = BUFFER_SIZE + 1;
		while (cap < len + i + 1)
			cap *= 2;
		temp = malloc(cap);
		if (!temp)
		return (NULL);
		i = 0;
		while (i < len)
		{
			temp[i] = str[i];
			i++;
		}

		free(str);
	}
	i = len;
	while (buffer[j])
	temp[i++] = buffer[j++];
	temp[i] = '\0';
	return (temp);
}

char	*read_line(int fd, char *str, char *buffer, int bytes)
{
	char	*temp;

	while (bytes > 0)
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
			temp = append_line(str, buffer, NULL, 0);
			if (!temp)
			{
				free(str);
				return (NULL);
			}
			str = temp;
			if (has_newline(buffer))
				return (str);
		}
	}
	return (str);
}
