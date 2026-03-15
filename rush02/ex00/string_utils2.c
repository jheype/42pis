/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 12:27:40 by wgolbert          #+#    #+#             */
/*   Updated: 2026/03/15 12:27:43 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strtrim_spaces(char *str)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] && ft_is_space(str[start]))
		start++;
	while (end >= start && ft_is_space(str[end]))
		end--;
	return (ft_substr(str, start, end - start + 1));
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;
	int		i;
	int		j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
		return (free(s1), NULL);
	i = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

int	ft_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
