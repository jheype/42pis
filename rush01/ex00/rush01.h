/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:59:46 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/08 17:06:29 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

int		parse_input(char *str, int clues[16]);
int		solve(int grid[4][4], int clues[16], int pos);

int		is_safe(int grid[4][4], int row, int col, int num);
int		check_row_views(int grid[4][4], int row, int clues[16]);
int		check_col_views(int grid[4][4], int col, int clues[16]);

int		count_visible_left(int line[4]);
int		count_visible_right(int line[4]);
int		count_visible_top(int grid[4][4], int col);
int		count_visible_bottom(int grid[4][4], int col);

void	print_grid(int grid[4][4]);
void	print_error(void);

#endif
