/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_group3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:07:42 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/15 15:10:49 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	print_hundreds_pt(t_dict *dict, int size,
		char *chunk, int *first)
{
	char	*word;

	if (ft_strcmp(chunk, "100") == 0)
	{
		word = dict_get_value(dict, size, "100");
		if (!word)
			return (0);
		print_word(word, first);
		return (1);
	}
	word = get_hundred_word(dict, size, chunk);
	if (!word)
		return (0);
	print_word(word, first);
	if (chunk[1] != '0' || chunk[2] != '0')
		print_sep(" e");
	return (1);
}

static int	convert_chunk_pt(t_dict *dict, int size,
		char *chunk, int *first)
{
	char	two[3];
	int		len;

	len = ft_strlen(chunk);
	if (len == 1)
		return (print_units(dict, size, chunk[0], first));
	if (len == 2)
		return (print_tens_and_units_pt(dict, size, chunk, first));
	if (chunk[0] != '0')
	{
		if (!print_hundreds_pt(dict, size, chunk, first))
			return (0);
	}
	two[0] = chunk[1];
	two[1] = chunk[2];
	two[2] = '\0';
	return (print_tens_and_units_pt(dict, size, two, first));
}

static int	convert_chunk_fr(t_dict *dict, int size,
		char *chunk, int *first)
{
	char	*hundred;
	char	two[3];
	int		len;

	len = ft_strlen(chunk);
	hundred = dict_get_value(dict, size, "100");
	if (!hundred)
		return (0);
	if (len == 1)
		return (print_units(dict, size, chunk[0], first));
	if (len == 2)
		return (print_tens_and_units_fr(dict, size, chunk, first));
	if (chunk[0] != '0')
	{
		if (!print_units(dict, size, chunk[0], first))
			return (0);
		print_word(hundred, first);
	}
	two[0] = chunk[1];
	two[1] = chunk[2];
	two[2] = '\0';
	return (print_tens_and_units_fr(dict, size, two, first));
}

static int	convert_chunk_en(t_dict *dict, int size,
		char *chunk, int *first)
{
	char	*hundred;
	char	two[3];
	int		len;

	len = ft_strlen(chunk);
	hundred = dict_get_value(dict, size, "100");
	if (!hundred)
		return (0);
	if (len == 1)
		return (print_units(dict, size, chunk[0], first));
	if (len == 2)
		return (print_tens_and_units_en(dict, size, chunk, first));
	if (chunk[0] != '0')
	{
		if (!print_units(dict, size, chunk[0], first))
			return (0);
		print_word(hundred, first);
	}
	two[0] = chunk[1];
	two[1] = chunk[2];
	two[2] = '\0';
	return (print_tens_and_units_en(dict, size, two, first));
}

int	convert_chunk(t_dict *dict, int size, char *chunk,
		t_chunk_ctx *cctx)
{
	if (cctx->lang == LANG_PT)
		return (convert_chunk_pt(dict, size, chunk, cctx->first));
	if (cctx->lang == LANG_FR)
		return (convert_chunk_fr(dict, size, chunk, cctx->first));
	return (convert_chunk_en(dict, size, chunk, cctx->first));
}
