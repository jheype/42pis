/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:07:45 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/15 15:07:46 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*make_scale_key(int group_index)
{
	char	*key;
	int		zeros;
	int		i;

	if (group_index <= 0)
		return (NULL);
	zeros = group_index * 3;
	key = (char *)malloc(zeros + 2);
	if (!key)
		return (NULL);
	key[0] = '1';
	i = 1;
	while (i <= zeros)
	{
		key[i] = '0';
		i++;
	}
	key[i] = '\0';
	return (key);
}

int	is_chunk_zero(char *chunk)
{
	int	i;

	i = 0;
	while (chunk[i])
	{
		if (chunk[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char	*chunk_from_number(char *num, int start, int len)
{
	return (ft_substr(num, start, len));
}

int	group_count(char *num)
{
	int	len;
	int	count;

	len = ft_strlen(num);
	count = len / 3;
	if (len % 3)
		count++;
	return (count);
}

int	has_nonzero_group_after(char *num, int current_group,
		int groups, int first_len)
{
	int		start;
	int		len;
	char	*chunk;
	int		i;

	i = current_group + 1;
	while (i < groups)
	{
		len = 3;
		if (i == 0)
			len = first_len;
		start = first_len + ((i - 1) * 3);
		if (i == 0)
			start = 0;
		chunk = chunk_from_number(num, start, len);
		if (!chunk)
			return (0);
		if (!is_chunk_zero(chunk))
			return (free(chunk), 1);
		free(chunk);
		i++;
	}
	return (0);
}
