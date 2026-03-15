/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:00:52 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/08 17:00:54 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_safe(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num)
			return (0);
		if (grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_row_views(int grid[4][4], int row, int clues[16])
{
	int	line[4];
	int	col;
	int	left_clue;
	int	right_clue;

	col = 0;
	while (col < 4)
	{
		line[col] = grid[row][col];
		col++;
	}
	left_clue = clues[8 + row];
	right_clue = clues[12 + row];
	if (count_visible_left(line) != left_clue)
		return (0);
	if (count_visible_right(line) != right_clue)
		return (0);
	return (1);
}

int	check_col_views(int grid[4][4], int col, int clues[16])
{
	int	top_clue;
	int	bottom_clue;

	top_clue = clues[col];
	bottom_clue = clues[4 + col];
	if (count_visible_top(grid, col) != top_clue)
		return (0);
	if (count_visible_bottom(grid, col) != bottom_clue)
		return (0);
	return (1);
}
