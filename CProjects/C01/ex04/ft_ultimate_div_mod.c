/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:33:10 by jode-alm          #+#    #+#             */
/*   Updated: 2026/02/26 15:25:05 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*int	main(void)
{
	int	numero_a;
	int	numero_b;

	numero_a = 42;
	numero_b = 10;

	ft_ultimate_div_mod(&numero_a, &numero_b);

	printf("Resultado da divisão: %d\n", numero_a);
	printf("Resultado do resto: %d\n", numero_b);

	return(0);
}*/
