/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_group2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:07:36 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/15 15:09:23 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_tens_and_units_en(t_dict *dict, int size,
		char *two, int *first)
{
	char	key[3];
	char	*word;

	if (two[0] == '0')
		return (print_units(dict, size, two[1], first));
	if (two[0] == '1')
		return (print_teens(dict, size, two, first));
	key[0] = two[0];
	key[1] = '0';
	key[2] = '\0';
	word = dict_get_value(dict, size, key);
	if (!word)
		return (0);
	print_word(word, first);
	if (two[1] != '0')
	{
		print_sep("-");
		return (print_units_compact(dict, size, two[1], first));
	}
	return (1);
}

int	print_tens_and_units_pt(t_dict *dict, int size,
		char *two, int *first)
{
	char	key[3];
	char	*word;

	if (two[0] == '0')
		return (print_units(dict, size, two[1], first));
	if (two[0] == '1')
		return (print_teens(dict, size, two, first));
	key[0] = two[0];
	key[1] = '0';
	key[2] = '\0';
	word = dict_get_value(dict, size, key);
	if (!word)
		return (0);
	print_word(word, first);
	if (two[1] != '0')
	{
		print_sep(" e");
		return (print_units(dict, size, two[1], first));
	}
	return (1);
}

static int	print_tens_word(t_dict *dict, int size,
		char tens_digit, int *first)
{
	char	key[3];
	char	*word;

	key[0] = tens_digit;
	key[1] = '0';
	key[2] = '\0';
	word = dict_get_value(dict, size, key);
	if (!word)
		return (0);
	print_word(word, first);
	return (1);
}

int	print_tens_and_units_fr(t_dict *dict, int size,
		char *two, int *first)
{
	if (two[0] == '0')
		return (print_units(dict, size, two[1], first));
	if (two[0] == '1')
		return (print_teens(dict, size, two, first));
	if (two[1] == '1' && two[0] != '8')
	{
		if (!print_tens_word(dict, size, two[0], first))
			return (0);
		print_sep(" et");
		return (print_units(dict, size, two[1], first));
	}
	if (!print_tens_word(dict, size, two[0], first))
		return (0);
	if (two[1] != '0')
	{
		print_sep("-");
		return (print_units_compact(dict, size, two[1], first));
	}
	return (1);
}

char	*get_hundred_word(t_dict *dict, int size, char *chunk)
{
	char	key[4];

	if (chunk[0] == '1')
		return (dict_get_value(dict, size, "101"));
	key[0] = chunk[0];
	key[1] = '0';
	key[2] = '0';
	key[3] = '\0';
	return (dict_get_value(dict, size, key));
}
