/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:28:45 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/15 14:31:11 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	grow_buffer(t_buf *buf)
{
	char	*new_data;
	int		i;

	buf->cap *= 2;
	new_data = (char *)malloc(buf->cap);
	if (!new_data)
		return (0);
	i = 0;
	while (i < buf->len)
	{
		new_data[i] = buf->data[i];
		i++;
	}
	free(buf->data);
	buf->data = new_data;
	return (1);
}

static char	*finalize_read(t_buf *buf, int fd)
{
	close(fd);
	if (buf->len + 1 >= buf->cap && !grow_buffer(buf))
	{
		free(buf->data);
		return (NULL);
	}
	buf->data[buf->len] = '\0';
	return (buf->data);
}

char	*read_file(char *filename)
{
	int		fd;
	int		bytes;
	t_buf	buf;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf.cap = 1024;
	buf.len = 0;
	buf.data = (char *)malloc(buf.cap);
	if (!buf.data)
		return (close(fd), (void *)0);
	bytes = 1;
	while (bytes > 0)
	{
		if (buf.len + 512 >= buf.cap && !grow_buffer(&buf))
			return (close(fd), free(buf.data), (void *)0);
		bytes = read(fd, buf.data + buf.len, 512);
		if (bytes < 0)
			return (close(fd), free(buf.data), (void *)0);
		buf.len += bytes;
	}
	return (finalize_read(&buf, fd));
}
