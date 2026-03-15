/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:27:36 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/08 02:32:07 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j])
		{
			j++;
		}
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char *haystack = "Explorando o ecossistema C";
	char *needle1 = "ecossistema";
	char *needle2 = "Python";
	char *needle3 = "";

	// Teste 1: Encontrando uma palavra
	printf("Teste 1 (Sucesso): %s\n", ft_strstr(haystack, needle1));

	// Teste 2: Palavra inexistente (deve retornar NULL/0)
	char *res2 = ft_strstr(haystack, needle2);
	if (res2 == 0)
		printf("Teste 2 (Não encontrado): O ponteiro retornado é NULL\n");

	// Teste 3: Agulha vazia (deve retornar a string inteira)
	printf("Teste 3 (Vazia): %s\n", ft_strstr(haystack, needle3));

	return (0);
}*/
