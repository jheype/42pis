/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:51:46 by jode-alm          #+#    #+#             */
/*   Updated: 2026/02/25 19:16:45 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0' - 1;
	while (++a <= '7')
	{
		b = a;
		while (++b <= '8')
		{
			c = b;
			while (++c <= '9')
			{
				write(1, &a, 1);
				write(1, &b, 1);
				write(1, &c, 1);
				if (a != 7 || b != 8 || c != 9)
				{
					write(1, ", ", 2);
				}
			}
		}
	}
}
//MAIN
//int	main(void)
//{
//	ft_print_comb();
//	return (0);
//}
