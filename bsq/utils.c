/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <jode-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:06:47 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/17 17:37:07 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	free_map(t_map *map)
{
	int	i;
 
	if (!map->grid)
		return ;
	i = 0;
	while (i < map->rows)
	{
		if (map->grid[i])
			free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}