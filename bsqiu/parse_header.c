/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:36:43 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/18 15:16:57 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	header_len(char *content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] != '\n')
		return (-1);
	return (i);
}

static int	valid_symbols(char a, char b, char c)
{
	if (a == b || a == c || b == c)
		return (0);
	return (1);
}

static int	parse_rows(char *content, int len)
{
	int	i;
	int	rows;
	int	digit_count;

	i = 0;
	rows = 0;
	digit_count = 0;
	while (i < len - 3)
	{
		if (!ft_isdigit(content[i]))
			return (0);
		digit_count++;
		if (digit_count > 7)
			return (0);
		rows = rows * 10 + (content[i] - '0');
		i++;
	}
	if (rows <= 0)
		return (0);
	return (rows);
}

int	parse_header(char *content, t_map *map, int *map_start)
{
	int	len;

	len = header_len(content);
	if (!content || !map || !map_start || len < 4)
		return (0);
	map->empty = content[len - 3];
	map->obstacle = content[len - 2];
	map->full = content[len - 1];
	if (!valid_symbols(map->empty, map->obstacle, map->full))
		return (0);
	map->rows = parse_rows(content, len);
	if (map->rows <= 0)
		return (0);
	*map_start = len + 1;
	return (1);
}
