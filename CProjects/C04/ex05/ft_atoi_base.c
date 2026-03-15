/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <jode-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:54:58 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/11 22:07:00 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
		i++;
	if (i <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_get_sign(char **str)
{
	int	sign;

	sign = 1;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	base_len;
	int	index;
	int	sign;

	if (!ft_base_valid(base))
		return (0);
	base_len = ft_base_len(base);
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = ft_get_sign(&str);
	index = ft_index(*str, base);
	while (index != -1)
	{
		result = result * base_len + index;
		str++;
		index = ft_index(*str, base);
	}
	return (result * sign);
}