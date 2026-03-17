/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:02:45 by resantos          #+#    #+#             */
/*   Updated: 2026/03/17 20:12:00 by resantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int **copy_map(t_map *map)
static t_max	set_numbers(t_map *map, int **num_map)
static int	get_cell_value(int	**grid, int i, int j)

int	solve_bsq(t_map *map)
{
	t_max	max;
	int		**num_map;

	num_map = copy_map(&map);
	if (!num_map)
		return (0);
	max = set_numbers(num_map);
	draw_square(&map, &max);
	return (1);
}

static int **copy_map(t_map *map)
{
	int	*num_map;
	int	i;
	int	j;

	num_map = malloc(sizeof(int *) * map->rows);
	if (!num_map)
		return NULL;
	while (i < map->rows)
	{
		num_map[i] = malloc(sizeof(int) * map->cols);
		if (!num_map[i])
		{
			j = 0;
			while (j < i)
			{
				free(num_map[j]);
				j++;
			}
			free(num_map);
			return NULL;
		}
		i++;
	}
	return (num_map);
}

static t_max	set_numbers(t_map *map, int **num_map)
{
	int		i;
	int		j;
	t_max	max;
	
	max.value = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->grid[i][j] == map->obstacle)
				num_map[i][j] = 0;
			else if (i == 0 || j == 0)
				num_map[i][j] = 1;
			else
				num_map[i][j] = get_cell_value(num_map, i, j);
			if (num_map[i][j] > max.value)
			{
				max.value = num_map[i][j];
				max.row = i;
				max.col = j;
			}
			j++;
		}
	}
	return (max);
}

static int	get_cell_value(int	**grid, int i, int j)
{
	int	value;
	int	min;

	min = min3(grid[i - 1][j], grid[i][j - 1], grid[i - 1][j - 1]);
	value = 1 + min;
	return (value);
}
