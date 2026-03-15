/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:19:46 by jode-alm          #+#    #+#             */
/*   Updated: 2026/02/26 15:23:59 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	numero_a;
	int	numero_b;
	int	resultado_divisao;
	int	resultado_resto;

	numero_a = 42;
	numero_b = 10;

	ft_div_mod(numero_a, numero_b, &resultado_divisao, &resultado_resto);

	printf("%d divido por %d\n\n", numero_a, numero_b);
	printf("Resultado da divisão: %d\n", resultado_divisao);
	printf("Resultado resto: %d\n", resultado_resto);
}*/
