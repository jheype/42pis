/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pea <joaopedroa2707@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:07:33 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/16 00:26:29 by joao-pea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"


// no struct ctx, definimos ctx.first = 1;
// primeira palavra (ex: "quarenta"): o ponteiro *first é 1.
// o if (!*first) da false. Ele não imprime espaço, só imprime "quarenta"
// e muda o *first para 0.
// segunda palavra (ex: "dois") o ponteiro *first agora é 0.
// o if (!*first) da verdadeiro, Ele imprime um " ", e depois imprime "dois"
void	print_word(char *word, int *first)
{
	if (!word)
		return ;
	if (!*first) // se nao for a primeira palavra
		write(1, " ", 1); // imprima um espaço antes da palavra
	ft_putstr(word);
	*first = 0; // agora, avise que a primeira palavra já passou
}

void	print_sep(char *sep)
{
	if (!sep)
		return ;
	ft_putstr(sep);
}

int	print_units(t_dict *dict, int size, char c, int *first)
{
	char	key[2];
	char	*word;

	if (c == '0')
		return (1);
	key[0] = c;
	key[1] = '\0';
	word = dict_get_value(dict, size, key);
	if (!word)
		return (0);
	print_word(word, first);
	return (1);
}

int	print_units_compact(t_dict *dict, int size, char c, int *first)
{
	char	key[2];
	char	*word;

	if (c == '0')
		return (1);
	key[0] = c;
	key[1] = '\0';
	word = dict_get_value(dict, size, key);
	if (!word)
		return (0);
	ft_putstr(word);
	*first = 0;
	return (1);
}

int	print_teens(t_dict *dict, int size, char *two, int *first)
{
	char	key[3];
	char	*word;

	key[0] = two[0];
	key[1] = two[1];
	key[2] = '\0';
	word = dict_get_value(dict, size, key);
	if (!word)
		return (0);
	print_word(word, first);
	return (1);
}
