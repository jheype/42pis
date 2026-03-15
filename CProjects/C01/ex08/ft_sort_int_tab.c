/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:38:47 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/01 18:17:04 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	swap;
	int	count;

	count = 0;
	while (count < (size - 1))
	{
		if (tab[count] > tab[count + 1])
		{
			swap = tab[count];
			tab[count] = tab[count + 1];
			tab[count + 1] = swap;
			count = 0;
		}
		else
			count++;
	}
}

/*int	main(void)
{
	int	my_tab[] = {23, 15, 86, 10};
	int	i = 0;
	int	n = 4;

	printf("Original: ");
	while (i < n)
	{
		printf("%d ", my_tab[i]);
		i++;
	}

	ft_sort_int_tab(my_tab, n);

	i = 0;
	printf("\nOrdenado: ");
	while (i < n)
	{
		printf("%d ", my_tab[i]);
		i++;
	}
	printf("\n");

	return(0);
}*/
