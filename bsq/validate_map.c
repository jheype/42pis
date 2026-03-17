/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <jode-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:50:14 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/17 17:54:27 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	get_line_len(char *content, int start)
{
	int	len;

	len = 0;
	while (content[start + len] && content[start + len] != '\n')
		len++;
	return (len);
}

static void	free_grid(t_map *map, int until)
{
	int	k;

	k = 0;
	while (k < until)
		free(map->grid[k++]);
	free(map->grid);
	map->grid = NULL;
}

int	validate_map(char *content, t_map *map, int map_start)
{
	int	i;
	int	j;
	int	line_count;

	map->cols = get_line_len(content, map_start);
	if (map->cols <= 0)
		return (0);
	i = map_start;
	line_count = 0;
	while (content[i])
	{
		j = 0;
		while (j < map->cols)
		{
			if (content[i + j] != map->empty && content[i + j] != map->obstacle)
				return (0);
			j++;
		}
		if (content[i + j] != '\n' && content[i + j] != '\0')
			return (0);
		line_count++;
		i += map->cols + (content[i + map->cols] == '\n');
	}
	return (line_count == map->rows);
}

int	build_grid(char *content, t_map *map, int map_start)
{
	int	i;
	int	j;
	int	k;

	map->grid = (char **)malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		return (0);
	i = map_start;
	k = 0;
	while (k < map->rows)
	{
		map->grid[k] = (char *)malloc(sizeof(char) * (map->cols + 1));
		if (!map->grid[k])
		{
			free_grid(map, k);
			return (0);
		}
		j = 0;
		while (j < map->cols)
			map->grid[k][j++] = content[i++];
		map->grid[k++][j] = '\0';
		if (content[i] == '\n')
			i++;
	}
	return (1);
}
