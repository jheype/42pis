/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pea <joaopedroa2707@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:07:52 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/16 00:22:48 by joao-pea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	process_group(t_dict *dict, int size, t_convert_ctx *ctx)
{
	char	*chunk;
	int		ok;

	chunk = chunk_from_number(ctx->num, ctx->start, get_chunk_len(ctx)); // chama para cortar o tamanho exato do grupo atual
	// isso gera uma nova string isolada no heap cmo malloc (ex: "000")
	if (!chunk)
		return (0);
	ok = 1; // assume que vai dar tudo certo
	// aqui a função olha para o grupo que acabou de ser cortado
	// se o grupo for exatamente "000", a função isso que é lixo, não imprimeda nada e não trduz nada
	// o if da falso, pula todo o processo da gramatica
	// se o grupo for "123", ele chama process_nonzero_chunk
	// para aplicar as regras do "Um mil", imprimir a escala, etc.
	if (!is_chunk_zero(chunk))
		ok = process_nonzero_chunk(dict, size, chunk, ctx);
	free(chunk);
	return (ok);
}

int	convert_number(t_dict *dict, int size, char *num, t_lang lang)
{
	t_convert_ctx	ctx; // A mochila na stack

	// caso especial do zero absoluto
	if (ft_strcmp(num, "0") == 0)
		return (ft_putstr(dict_get_value(dict, size, "0")), 1);
	init_ctx(&ctx, num, lang);
	while (ctx.i < ctx.groups)
	{
		if (!process_group(dict, size, &ctx))
			return (0);
		// andando com o cursor
		ctx.start += get_chunk_len(&ctx);
		ctx.i++;
	}
	return (1);
}
