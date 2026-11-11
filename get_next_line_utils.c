/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:52:42 by rihammou          #+#    #+#             */
/*   Updated: 2026/11/11 15:37:13 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*append_stash(char *stash, char *buffer)
{
	char	*temp;
	int		i;
	int		j;
	int		len;
	
	j = 0;
	i = 0;
	len = 0;
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


char	*found_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char *copy_line(int fd, char *buffer, char *stash, ssize_t bytes, char *line)
{
	int	end;
	int	i;
	int	len;
	
	len = 0;
	i = 0;
	end = 0;
	while (!end)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		while(buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		len += i;
		if (i == bytes && buffer[i] != '\n')
		{
			stash = append_stash(stash, buffer);
			i = 0;
		}
		else if (buffer[i] == '\n')
		{
			stash = append_stash(stash, buffer);
			line = found_line(stash);
			end = 1;
			return (line);
		}
	}
}

