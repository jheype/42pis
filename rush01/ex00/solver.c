/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:00:47 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/08 17:00:48 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	row_is_complete(int grid[4][4], int row)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (grid[row][col] == 0)
			return (0);
		col++;
	}
	return (1);
}

static int	col_is_complete(int grid[4][4], int col)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (grid[row][col] == 0)
			return (0);
		row++;
	}
	return (1);
}

static int	check_current_state(int grid[4][4], int clues[16], int row, int col)
{
	if (row_is_complete(grid, row) && !check_row_views(grid, row, clues))
		return (0);
	if (col_is_complete(grid, col) && !check_col_views(grid, col, clues))
		return (0);
	return (1);
}

int	solve(int grid[4][4], int clues[16], int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == 16)
		return (1);
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (check_current_state(grid, clues, row, col))
			{
				if (solve(grid, clues, pos + 1))
					return (1);
			}
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
