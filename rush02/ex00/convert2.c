/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:07:48 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/15 15:11:06 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	print_scale_word(t_dict *dict, int size,
							int group_index, int *first)
{
	char	*scale_key;
	char	*scale_word;

	scale_key = make_scale_key(group_index);
	if (!scale_key)
		return (0);
	scale_word = dict_get_value(dict, size, scale_key);
	free(scale_key);
	if (!scale_word)
		return (0);
	print_word(scale_word, first);
	return (1);
}

static int	get_first_len(char *num)
{
	int	len;

	len = ft_strlen(num) % 3;
	if (!len)
		return (3);
	return (len);
}

int	get_chunk_len(t_convert_ctx *ctx)
{
	if (ctx->i == 0)
		return (ctx->first_len);
	return (3);
}

void	init_ctx(t_convert_ctx *ctx, char *num, t_lang lang)
{
	ctx->groups = group_count(num);
	ctx->first_len = get_first_len(num);
	ctx->i = 0;
	ctx->start = 0;
	ctx->first = 1;
	ctx->lang = lang;
	ctx->num = num;
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
		skip_chunk = 1;
	if (!skip_chunk && !convert_chunk(dict, size, chunk, &cctx))
		return (0);
	if (ctx->groups - ctx->i - 1 > 0
		&& !print_scale_word(dict, size, ctx->groups - ctx->i - 1, &ctx->first))
		return (0);
	if (ctx->lang == LANG_EN && ctx->groups - ctx->i - 1 > 0
		&& has_nonzero_group_after(ctx->num, ctx->i,
			ctx->groups, ctx->first_len))
		print_sep(",");
	return (1);
}
