/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 20:58:57 by jode-alm          #+#    #+#             */
/*   Updated: 2026/02/25 16:01:54 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write(1, "N", 1);
	}
	else
	{
		write(1, "P", 1);
	}
}
//
//MAIN
//int	main(void)
//{
//	int	numero;
//	
//	printf("Digite um Número: ");
//	scanf("%d", &numero);
//
//	if (!numero)
//	{
//		printf("Não é um número");
//	}
//	else
//	{
//		ft_is_negative(numero);
//	}
//	printf("\n");
//	return (0);
//}
