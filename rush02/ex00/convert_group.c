/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:07:33 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/15 15:09:17 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_word(char *word, int *first)
{
	if (!word)
		return ;
	if (!*first)
		write(1, " ", 1);
	ft_putstr(word);
	*first = 0;
}

void	print_sep(char *sep)
{
	if (!sep)
		return ;
	ft_putstr(sep);
}

int	print_units(t_dict *dict, int size, char c, int *first)
{
	char	key[2];
	char	*word;

	if (c == '0')
		return (1);
	key[0] = c;
	key[1] = '\0';
	word = dict_get_value(dict, size, key);
	if (!word)
		return (0);
	print_word(word, first);
	return (1);
}

int	print_units_compact(t_dict *dict, int size, char c, int *first)
{
	char	key[2];
	char	*word;

	if (c == '0')
		return (1);
	key[0] = c;
	key[1] = '\0';
	word = dict_get_value(dict, size, key);
	if (!word)
		return (0);
	ft_putstr(word);
	*first = 0;
	return (1);
}

int	print_teens(t_dict *dict, int size, char *two, int *first)
{
	char	key[3];
	char	*word;

	key[0] = two[0];
	key[1] = two[1];
	key[2] = '\0';
	word = dict_get_value(dict, size, key);
	if (!word)
		return (0);
	print_word(word, first);
	return (1);
}
