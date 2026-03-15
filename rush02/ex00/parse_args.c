/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 12:30:49 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/15 15:11:35 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_valid_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	if (i > 39)
		return (0);
	return (1);
}

char	*normalize_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0' && str[i + 1])
		i++;
	return (ft_strdup(str + i));
}
