/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:31:51 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/15 14:33:48 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_dict(t_dict *dict, int size)
{
	int	i;

	if (!dict) // evitar segfault
		return ;
	i = 0;
	while (i < size)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}
