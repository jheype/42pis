/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:11:10 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/03 13:05:24 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i++] = '\0';
	}
	return (dest);
}

/*int	main(void)
{
	char	src[40] = "123456789";
	char	dest[40] = "abcdefg";
	char	*return_string;
	int	n = 5;

	printf("Dest is originally = '%s'\n", dest);
	return_string = ft_strncpy(dest, src, n);
	printf("Dest after = '%s'\n", dest);
}*/
