/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <jode-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:50:14 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/18 15:16:27 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	line_len(char *content, int start)
{
	int	len;

	len = 0;
	while (content[start + len] && content[start + len] != '\n')
		len++;
	return (len);
}

static int	valid_char(char c, t_map *map)
{
	return (c == map->empty || c == map->obstacle);
}

int	validate_map(char *content, t_map *map, int map_start)
{
	int	i;
	int	len;
	int	cur;
	int	lines;

	i = map_start;
	len = line_len(content, i);
	if (len <= 0)
		return (0);
	map->cols = len;
	lines = 0;
	while (content[i])
	{
		cur = 0;
		while (content[i + cur] && content[i + cur] != '\n')
			if (!valid_char(content[i + cur++], map))
				return (0);
		if (cur != len)
			return (0);
		lines++;
		i += cur + (content[i + cur] == '\n');
	}
	return (lines == map->rows);
}

int	build_grid(char *content, t_map *map, int map_start)
{
	int	i;
	int	j;
	int	k;

	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		return (0);
	i = map_start;
	k = 0;
	while (k < map->rows)
	{
		map->grid[k] = malloc(map->cols + 1);
		if (!map->grid[k])
			return (free_map(map), 0);
		j = 0;
		while (j < map->cols)
			map->grid[k][j++] = content[i++];
		map->grid[k][j] = '\0';
		i += (content[i] == '\n');
		k++;
	}
	return (1);
}
