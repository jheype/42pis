/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:00:28 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/08 17:00:32 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	init_grid(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	int	clues[16];
	int	grid[4][4];

	if (argc != 2)
	{
		print_error();
		return (0);
	}
	if (!parse_input(argv[1], clues))
	{
		print_error();
		return (0);
	}
	init_grid(grid);
	if (!solve(grid, clues, 0))
	{
		print_error();
		return (0);
	}
	print_grid(grid);
	return (0);
}
