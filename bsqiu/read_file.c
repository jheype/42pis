/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:07:21 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/18 15:10:03 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#define CHUNK_SIZE 1024

static void	copy_bytes(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*append_chunk(char *content, int old_size, char *buffer, int bytes_read)
{
	char	*new_content;

	new_content = (char *)malloc(sizeof(char) * (old_size + bytes_read + 1));
	if (!new_content)
	{
		free(content);
		return (NULL);
	}
	if (content)
		copy_bytes(new_content, content, old_size);
	copy_bytes(new_content + old_size, buffer, bytes_read);
	new_content[old_size + bytes_read] = '\0';
	free(content);
	return (new_content);
}

static char	*create_empty_content(void)
{
	char	*content;

	content = (char *)malloc(sizeof(char) * 1);
	if (!content)
		return (NULL);
	content[0] = '\0';
	return (content);
}

char	*read_file(int fd)
{
	char	buffer[CHUNK_SIZE];
	char	*content;
	int		total_size;
	int		bytes_read;

	content = NULL;
	total_size = 0;
	bytes_read = read(fd, buffer, CHUNK_SIZE);
	while (bytes_read > 0)
	{
		content = append_chunk(content, total_size, buffer, bytes_read);
		if (!content)
			return (NULL);
		total_size += bytes_read;
		bytes_read = read(fd, buffer, CHUNK_SIZE);
	}
	if (bytes_read < 0)
	{
		free(content);
		return (NULL);
	}
	if (!content)
		return (create_empty_content());
	return (content);
}
