/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:07:52 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/15 15:07:53 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	process_group(t_dict *dict, int size, t_convert_ctx *ctx)
{
	char	*chunk;
	int		ok;

	chunk = chunk_from_number(ctx->num, ctx->start, get_chunk_len(ctx));
	if (!chunk)
		return (0);
	ok = 1;
	if (!is_chunk_zero(chunk))
		ok = process_nonzero_chunk(dict, size, chunk, ctx);
	free(chunk);
	return (ok);
}

int	convert_number(t_dict *dict, int size, char *num, t_lang lang)
{
	t_convert_ctx	ctx;

	if (ft_strcmp(num, "0") == 0)
		return (ft_putstr(dict_get_value(dict, size, "0")), 1);
	init_ctx(&ctx, num, lang);
	while (ctx.i < ctx.groups)
	{
		if (!process_group(dict, size, &ctx))
			return (0);
		ctx.start += get_chunk_len(&ctx);
		ctx.i++;
	}
	return (1);
}
