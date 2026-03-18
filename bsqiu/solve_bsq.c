/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:02:45 by resantos          #+#    #+#             */
/*   Updated: 2026/03/18 16:08:36 by resantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	get_cell_value(int *prev, int *curr, int j)
{
	int	value;
	int	min;

	min = min3(prev[j], curr[j - 1], prev[j - 1]);
	value = 1 + min;
	return (value);
}

static void	swap_rows(int **prev, int **curr)
{
	int	*temp;

	temp = *prev;
	*prev = *curr;
	*curr = temp;
}

static void	set_numbers(t_map *map, t_square *max, int *prev, int *curr)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->grid[i][j] == map->obstacle)
				curr[j] = 0;
			else if (i == 0 || j == 0)
				curr[j] = 1;
			else
				curr[j] = get_cell_value(prev, curr, j);
			if (curr[j] > max->size)
			{
				max->size = curr[j];
				max->row = i;
				max->col = j;
			}
		}
		swap_rows(&prev, &curr);
	}
}

static void	init_row(int *row, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		row[i] = 0;
		i++;
	}
}

t_square	solve_bsq(t_map *map)
{
	t_square	max;
	int			*prev;
	int			*curr;

	max.size = 0;
	prev = malloc(sizeof(int) * map->cols);
	curr = malloc(sizeof(int) * map->cols);
	if (!prev || !curr)
	{
		free(prev);
		free(curr);
		return (max);
	}
	init_row(prev, map->cols);
	set_numbers(map, &max, prev, curr);
	draw_square(map, &max);
	free(prev);
	free(curr);
	return (max);
}
