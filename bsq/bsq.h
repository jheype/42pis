/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:17:14 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/17 20:11:01 by resantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

typedef struct s_square
{
	int	size;
	int	row;
	int	col;
}	t_square;

char		*read_file(int fd);
int			parse_header(char *content, t_map *map, int *map_start);
int			validate_map(char *content, t_map *map, int map_start);
int			build_grid(char *content, t_map *map, int map_start);
t_square	solve_bsq(t_map *map);
void		draw_square(t_map *map, t_square *max);
void		print_map(t_map *map);
void		print_error(void);
int			ft_strlen(char *str);
int			ft_isdigit(char c);
int			min3(int a, int b, int c);
void		free_map(t_map *map);

#endif
