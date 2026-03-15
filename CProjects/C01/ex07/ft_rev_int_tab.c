/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:01:15 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/01 19:26:44 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		swap = tab[i];
		tab[i] = tab[j];
		tab[j] = swap;
		i++;
		j--;
	}
}

int	main(void)
{
	int	my_tab[] = [25, 50, 75, 100];
	int	n = 4;
	int	i = 0;

	printf("Original: ");
	while (i < n)
	{
		printf("%d ", my_tab[i]);
		i++;
	}

	ft_rev_int_tab(my_tab, n);

	i = 0;
	printf("\nInvertido: ");
	while (i < n)
	{
		printf("%d ", my_tab[i]);
		i++;
	}
	printf("\n");

	return(0);
}
