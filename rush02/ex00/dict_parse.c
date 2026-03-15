/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:07:55 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/15 15:08:00 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	count_valid_lines(char *content)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] != '\n')
		{
			count++;
			while (content[i] && content[i] != '\n')
				i++;
		}
		if (content[i] == '\n')
			i++;
	}
	return (count);
}

static int	parse_line_values(char *line, t_dict *dict, int *idx, int colon)
{
	char	*raw[2];
	char	*key;
	char	*val;

	raw[0] = ft_substr(line, 0, colon);
	raw[1] = ft_substr(line, colon + 1, ft_strlen(line) - colon - 1);
	if (!raw[0] || !raw[1])
		return (free(raw[0]), free(raw[1]), 0);
	key = ft_strtrim_spaces(raw[0]);
	val = ft_strtrim_spaces(raw[1]);
	free(raw[0]);
	free(raw[1]);
	if (!key || !val || !key[0] || !val[0])
		return (free(key), free(val), 0);
	dict[*idx].key = key;
	dict[*idx].value = val;
	(*idx)++;
	return (1);
}

static int	parse_line(char *line, t_dict *dict, int *idx)
{
	int	colon;
	int	i;

	colon = -1;
	i = -1;
	while (line[++i])
	{
		if (line[i] == ':')
		{
			if (colon != -1)
				return (0);
			colon = i;
		}
	}
	if (colon == -1)
		return (0);
	return (parse_line_values(line, dict, idx, colon));
}

int	fill_dict(char *content, t_dict *dict)
{
	int		s;
	int		e;
	int		idx;
	char	*line;

	s = 0;
	idx = 0;
	while (content[s])
	{
		e = s;
		while (content[e] && content[e] != '\n')
			e++;
		if (e > s)
		{
			line = ft_substr(content, s, e - s);
			if (!line || !parse_line(line, dict, &idx))
				return (free(line), 0);
			free(line);
		}
		if (!content[e])
			break ;
		s = e + 1;
	}
	return (idx);
}

t_dict	*parse_dict(char *content, int *size)
{
	t_dict	*dict;
	int		real_sz;

	*size = count_valid_lines(content);
	if (*size <= 0)
		return (NULL);
	dict = (t_dict *)malloc(sizeof(t_dict) * (*size));
	if (!dict)
		return (NULL);
	real_sz = fill_dict(content, dict);
	if (!real_sz)
		return (free_dict(dict, *size), (void *)0);
	*size = real_sz;
	if (!has_required_basic_keys(dict, *size))
		return (free_dict(dict, *size), (void *)0);
	return (dict);
}
