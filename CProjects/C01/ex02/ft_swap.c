/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:08:54 by jode-alm          #+#    #+#             */
/*   Updated: 2026/02/26 15:23:27 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*int	main(void)
{
	int	numero_a;
	int	numero_b;

	numero_a = 10;
	numero_b = 42;

	printf(" ====== Antes da troca ===== \n");

	printf("Valor antes da troca A: %d\n", numero_a);
	printf("Valor antes da troca B: %d\n", numero_b);

	ft_swap(&numero_a, &numero_b);

	printf(" ===== Depois da troca ==== \n");

	printf("Valor depois da troca A: %d\n", numero_a);
	printf("Valor depois da troca B: %d\n", numero_b);

	return(0);
}*/
