/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:00:37 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/08 17:05:50 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	print_grid(int grid[4][4])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = grid[row][col] + '0';
			ft_putchar(c);
			if (col < 3)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
