/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:00:56 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/08 17:00:59 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_visible_left(int line[4])
{
	int	i;
	int	max;
	int	visible;

	i = 0;
	max = 0;
	visible = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			visible++;
		}
		i++;
	}
	return (visible);
}

int	count_visible_right(int line[4])
{
	int	i;
	int	max;
	int	visible;

	i = 3;
	max = 0;
	visible = 0;
	while (i >= 0)
	{
		if (line[i] > max)
		{
			max = line[i];
			visible++;
		}
		i--;
	}
	return (visible);
}

int	count_visible_top(int grid[4][4], int col)
{
	int	row;
	int	max;
	int	visible;

	row = 0;
	max = 0;
	visible = 0;
	while (row < 4)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		row++;
	}
	return (visible);
}

int	count_visible_bottom(int grid[4][4], int col)
{
	int	row;
	int	max;
	int	visible;

	row = 3;
	max = 0;
	visible = 0;
	while (row >= 0)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		row--;
	}
	return (visible);
}
