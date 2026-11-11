/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:37:45 by rihammou          #+#    #+#             */
/*   Updated: 2026/11/11 15:23:05 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *stash;
	char		*buffer;
	char		*line;
	ssize_t		bytes;

	stash = NULL;
	copy_line(fd, buffer, stash, bytes, line);
	
}
