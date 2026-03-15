/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 12:27:23 by wgolbert          #+#    #+#             */
/*   Updated: 2026/03/15 12:27:26 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	grow_line_buffer(char **buf, int *cap)
{
	char	*new_buf;
	int		i;
	int		old_cap;

	old_cap = *cap;
	*cap *= 2;
	new_buf = (char *)malloc(*cap);
	if (!new_buf)
		return (0);
	i = 0;
	while (i < old_cap)
	{
		new_buf[i] = (*buf)[i];
		i++;
	}
	free(*buf);
	*buf = new_buf;
	return (1);
}

char	*read_stdin_line(void)
{
	char	c;
	char	*buf;
	int		cap;
	int		len;
	int		bytes;

	cap = 64;
	len = 0;
	buf = (char *)malloc(cap);
	if (!buf)
		return (NULL);
	bytes = read(0, &c, 1);
	while (bytes > 0)
	{
		if (c == '\n')
			break ;
		if (len + 1 >= cap && !grow_line_buffer(&buf, &cap))
			return (free(buf), NULL);
		buf[len++] = c;
		bytes = read(0, &c, 1);
	}
	if (bytes <= 0 && len == 0)
		return (free(buf), NULL);
	buf[len] = '\0';
	return (buf);
}

int	process_stdin_mode(t_dict *dict, int size, t_lang lang)
{
	char	*line;
	char	*norm;

	line = read_stdin_line();
	while (line)
	{
		if (!is_valid_number(line))
			ft_putstr("Error\n");
		else
		{
			norm = normalize_number(line);
			if (!norm || !convert_number(dict, size, norm, lang))
				ft_putstr("Dict Error\n");
			else
				ft_putstr("\n");
			free(norm);
		}
		free(line);
		line = read_stdin_line();
	}
	return (1);
}
