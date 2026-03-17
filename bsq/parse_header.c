/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:36:43 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/17 15:50:22 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	gethlen(char *content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] != '\n')
		return (-1);
	return (i);
}

static int	val_symb(char empty, char obstacle, char full)
{
	if (empty == obstacle || empty == full || obstacle == full)
		return (0);
	return (1);
}

static int	parse_rows(char *content, int len)
{
	int	i;
	int	rows;

	i = 0;
	rows = 0;
	while (i < len - 3)
	{
		if (!ft_isdigit(content[i]))
			return (0);
		rows = row * 10 + (content[i] - '0');
		i++;
	}
	if (rows <= 0)
		return (0);
	return (rows);
}

int	parse_header(char *content, t_map *map, int *map_start)
{
	int	len;

	if (!content || !map || !map_start)
		return (0);
	len = gethlen(content);
	if (len < 4)
		return (0);
	map->empty = content[len - 3];
	map->obstacle = content[len - 2];
	map->full = content[len - 1];
	if (!val_symb(map->empty, map->obstacle, map->full))
		return (0);
	map->rows = parse_rows(content, len);
	if (map->rows <= 0)
		return (0);
	*map_start = len + 1;
	return (1);
}
