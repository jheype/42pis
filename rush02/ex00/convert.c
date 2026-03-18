/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pea <joaopedroa2707@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:07:45 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/16 00:03:49 by joao-pea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*make_scale_key(int group_index)
{
	char	*key;
	int		zeros;
	int		i;

	if (group_index <= 0)
		return (NULL);
	zeros = group_index * 3; // se for o grupo 1 (mil)> 1 * 3 = 3 zeros. Cria a string 1 + 000 = 1000
	key = (char *)malloc(zeros + 2); // '1' + zeros + '\0'
	if (!key)
		return (NULL);
	key[0] = '1'; // a primeira letra é sempre '1'
	i = 1;
	while (i <= zeros) // preenche o resto com '0'
	{
		key[i] = '0';
		i++;
	}
	key[i] = '\0';
	return (key);
}

// verifica se só tem zero
// ele pula os zeros
int	is_chunk_zero(char *chunk)
{
	int	i;

	i = 0;
	while (chunk[i])
	{
		if (chunk[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char	*chunk_from_number(char *num, int start, int len)
{
	return (ft_substr(num, start, len));
}

// contar quantos grupos de 3 digitos o numero tem.
int	group_count(char *num)
{
	int	len;
	int	count;
 
	len = ft_strlen(num); // EX: 42404042 (42milhoes, 404 mil e 42). o tamanho(len) é 8
	count = len / 3; // 8 / 3 = 2 (dois blocos de 3)
	if (len % 3) // o resto(8 % 3) é 2. Como tem resto, ele faz count++ (2 + 1 = 3 grupos no total)
		count++;
	return (count);
}

int	has_nonzero_group_after(char *num, int current_group,
		int groups, int first_len)
{
	int		start;
	int		len;
	char	*chunk;
	int		i;

	i = current_group + 1; // começa a olhar para o proximo grupo
	while (i < groups) // enquanto houver grupos para frente
	{
		len = 3;
		if (i == 0)
			len = first_len;
		start = first_len + ((i - 1) * 3);
		if (i == 0)
			start = 0;
		// matematica para calcular onde começa o proximo grupo
		chunk = chunk_from_number(num, start, len);
		if (!chunk)
			return (0);
		if (!is_chunk_zero(chunk)) // se achar algo diferente de zero
			return (free(chunk), 1); // avisa q tem numero
		free(chunk); // se for so zeros, joga no lixo e testa o proximo
		i++;
	}
	return (0);
}
