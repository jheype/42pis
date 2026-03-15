/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:38:41 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/04 15:23:21 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_alphanumeric(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (is_alphanumeric(str[i]))
		{
			if (i == 0 || !is_alphanumeric(str[i - 1]))
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 32;
			}
		}
		i++;
	}
	return (str);
}

int     main(void)
{
	char	name[100] = "hI, h_Ow_are yOu? 42words forty-two; fifty+and+one";
	printf("%s", ft_strcapitalize(name));
	return(0);	
}
