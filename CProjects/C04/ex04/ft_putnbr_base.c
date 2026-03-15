/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:36:04 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/11 19:09:38 by jode-alm         ###   ########.fr       */
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

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	char	c;
	int		base_len;

	if (!ft_base_valid(base))
		return ;
	base_len = ft_base_len(base);
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
	c = base[n % base_len];
	write(1, &c, 1);
}
