/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pea <joaopedroa2707@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:07:48 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/16 00:16:25 by joao-pea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	print_scale_word(t_dict *dict, int size,
							int group_index, int *first)
{
	char	*scale_key;
	char	*scale_word;

	scale_key = make_scale_key(group_index); // se for o grupo 2, essa função fabrica a string "1000000" por exemplo.
	if (!scale_key)
		return (0);
	scale_word = dict_get_value(dict, size, scale_key); // manda essa string pro dict_get_value procurar no dicionario. o dicionario devolve "million"
	free(scale_key); // free
	if (!scale_word)
		return (0);
	print_word(scale_word, first); // função print_word para jogar a palavra na tela
	return (1);
}

static int	get_first_len(char *num)
{
	int	len;

	len = ft_strlen(num) % 3; // pega o resto da divisão por 3
	if (!len) // se o resto for 0 (ex: tamanho 3, 6, 9...)
		return (3); // a primeira fatia tem 3 digitos
	return (len); // se sobrar 1 ou 2, esse é o tamanho da primeira fatia
}

int	get_chunk_len(t_convert_ctx *ctx)
{
	if (ctx->i == 0)
		return (ctx->first_len);
	return (3);
}

void	init_ctx(t_convert_ctx *ctx, char *num, t_lang lang)
{
	ctx->groups = group_count(num); // quantos grupos no total
	ctx->first_len = get_first_len(num); // qual o tamanho do 1 grupo
	ctx->i = 0; // indice 0
	ctx->start = 0; // o corte começa na posicao 0
	ctx->first = 1; // é a primeira palavra a ser impressa?
	ctx->lang = lang; // qual é o idioma?
	ctx->num = num; // o número original inteiro
}

int	process_nonzero_chunk(t_dict *dict, int size,
		char *chunk, t_convert_ctx *ctx)
{
	int			skip_chunk;
	t_chunk_ctx	cctx;

	cctx.first = &ctx->first;
	cctx.lang = ctx->lang;
	skip_chunk = 0;
	if (ctx->lang == LANG_PT && ft_strcmp(chunk, "1") == 0
		&& ctx->groups - ctx->i - 1 == 1)
		skip_chunk = 1; // ligar a flag para PULAR a tradução do número
	if (!skip_chunk && !convert_chunk(dict, size, chunk, &cctx))
		return (0);
	if (ctx->groups - ctx->i - 1 > 0
		&& !print_scale_word(dict, size, ctx->groups - ctx->i - 1, &ctx->first)) // se nao for o ultimo grupo, ele chama a função para imprimir a escala (mil, milhão e etc)
		return (0);
		// se for inglês
		// e não for o ultimo grupo
		// e tiver algum numero diferente de zero pela frente
		// chama print_sep(",") para colocar uma virgula
	if (ctx->lang == LANG_EN && ctx->groups - ctx->i - 1 > 0
		&& has_nonzero_group_after(ctx->num, ctx->i,
			ctx->groups, ctx->first_len))
		print_sep(",");
	return (1);
}
