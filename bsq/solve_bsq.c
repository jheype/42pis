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

static void	free_num_map(int **num_map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(num_map[i]);
		i++;
	}
	free(num_map);
}

static int	**copy_map(t_map *map)
{
	int	**num_map;
	int	i;
	int	j;

	num_map = (int **)malloc(sizeof(int *) * map->rows);
	if (!num_map)
		return (NULL);
	i = 0;
	while (i < map->rows)
	{
		num_map[i] = (int *)malloc(sizeof(int) * map->cols);
		if (!num_map[i])
			return (free_num_map(num_map, i), NULL);
		j = 0;
		while (j < map->cols)
		{
			if (map->grid[i][j] == map->obstacle)
				num_map[i][j] = 0;
			else
				num_map[i][j] = 1;
			j++;
		}
		i++;
	}
	return (num_map);
}

static int	get_cell_value(int **grid, int i, int j)
{
	if (i == 0 || j == 0)
		return (grid[i][j]);
	if (grid[i][j] == 0)
		return (0);
	return (1 + min3(grid[i - 1][j], grid[i][j - 1], grid[i - 1][j - 1]));
}

static t_square	set_numbers(t_map *map, int **num_map)
{
	t_square		max;
	int			i;
	int			j;

	max.size = 0;
	max.row = 0;
	max.col = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			num_map[i][j] = get_cell_value(num_map, i, j);
			if (num_map[i][j] > max.size)
			{
				max.size = num_map[i][j];
				max.row = i;
				max.col = j;
			}
			j++;
		}
		i++;
	}
	return (max);
}

t_square	solve_bsq(t_map *map)
{
	t_square	max;
	int			**num_map;

	num_map = copy_map(map);
	if (!num_map)
	{
		max.size = 0;
		max.row = 0;
		max.col = 0;
		return (max);
	}
	max = set_numbers(map, num_map);
	free_num_map(num_map, map->rows);
	return (max);
}