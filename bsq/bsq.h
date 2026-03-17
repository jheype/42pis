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

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

typedef struct s_max
{
	int	value;
	int	row;
	int	col;
}	t_max;

int		ft_strlen(char *str);
int		ft_isdigit(char c);
int		ft_atoi(char *str);
int		min3(int a, int b, int c);
void	ft_putstr_fd(char *str, int fd);
void	free_map(t_map *map);
int		parse_header(char *content, t_map *map, int *map_start);
char	*strncpy(char *dest, char *src, int size);
char	*read_file(int fd);
int		solve_bsq(t_map *map);
void	draw_square(t_map *map, t_max *max);
void	print_map(t_map *map);

#endif
