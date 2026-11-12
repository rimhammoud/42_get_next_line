/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:43:11 by rihammou          #+#    #+#             */
/*   Updated: 2026/11/12 10:04:59 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

# include <unistd.h>
#include <stdlib.h>

char *copy_line(int fd, char *buffer, char **stash, ssize_t bytes, char *line);

#endif
