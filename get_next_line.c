/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:37:45 by rihammou          #+#    #+#             */
/*   Updated: 2026/11/12 12:13:59 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash = read_stash(fd, stash, buffer);
	free(buffer);
	if (!stash)
		return (NULL);
	if (!stash[0])
		return (update_stash(stash, 0));
	size = 0;
	while (stash[size] && stash[size] != '\n')
		size++;
	if (stash[size] == '\n')
		size++;
	line = extract_line(stash, size + 1);
	stash = update_stash(stash, size);
	return (line);
}
