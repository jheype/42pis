/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:31:43 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/15 14:40:47 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*dict_get_value(t_dict *dict, int size, char *key)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (NULL);
}

static int	check_big_numbers(t_dict *dict, int size)
{
	char	*bigs[4];
	int		i;

	bigs[0] = "100";
	bigs[1] = "1000";
	bigs[2] = "1000000";
	bigs[3] = "1000000000";
	i = 0;
	while (i < 4)
	{
		if (dict_get_value(dict, size, bigs[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

static int	check_tens(t_dict *dict, int size)
{
	char	*tens[9];
	int		i;

	tens[0] = "10";
	tens[1] = "20";
	tens[2] = "30";
	tens[3] = "40";
	tens[4] = "50";
	tens[5] = "60";
	tens[6] = "70";
	tens[7] = "80";
	tens[8] = "90";
	i = 0;
	while (i < 9)
	{
		if (dict_get_value(dict, size, tens[i]) == NULL)
			return (0);
		i++;
	}
	return (check_big_numbers(dict, size));
}

int	has_required_basic_keys(t_dict *dict, int size)
{
	char	*units[11];
	int		i;

	units[0] = "0";
	units[1] = "1";
	units[2] = "2";
	units[3] = "3";
	units[4] = "4";
	units[5] = "5";
	units[6] = "6";
	units[7] = "7";
	units[8] = "8";
	units[9] = "9";
	units[10] = "11";
	i = 0;
	while (i < 11)
	{
		if (dict_get_value(dict, size, units[i]) == NULL)
			return (0);
		i++;
	}
	return (check_tens(dict, size));
}

t_lang	detect_lang(t_dict *dict, int size)
{
	char	*thousand;

	thousand = dict_get_value(dict, size, "1000");
	if (!thousand)
		return (LANG_EN);
	if (ft_strcmp(thousand, "mil") == 0)
		return (LANG_PT);
	if (ft_strcmp(thousand, "mille") == 0)
		return (LANG_FR);
	return (LANG_EN);
}
