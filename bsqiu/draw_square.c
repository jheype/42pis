/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:21:33 by resantos          #+#    #+#             */
/*   Updated: 2026/03/18 15:31:57 by resantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	draw_square(t_map *map, t_square *max)
{
	int	i;
	int	j;

	i = max->row;
	while (i > max->row - max->size)
	{
		j = max->col;
		while (j > max->col - max->size)
		{
			map->grid[i][j] = map->full;
			j--;
		}
		i--;
	}
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			write(1, &map->grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
