/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pea <joaopedroa2707@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:07:55 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/15 22:40:55 by joao-pea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// filtrar linhas válidas no dict
int	count_valid_lines(char *content)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] != '\n')
		{
			count++;
			while (content[i] && content[i] != '\n')
				i++;
		}
		if (content[i] == '\n')
			i++;
	}
	return (count);
}

static int	parse_line_values(char *line, t_dict *dict, int *idx, int colon)
{
	char	*raw[2];
	char	*key;
	char	*val;

	raw[0] = ft_substr(line, 0, colon); // aqui recebe tudo antes do :
	raw[1] = ft_substr(line, colon + 1, ft_strlen(line) - colon - 1); // esse recebe o lado direito (tudo depois do :)
	if (!raw[0] || !raw[1])
		return (free(raw[0]), free(raw[1]), 0);
	key = ft_strtrim_spaces(raw[0]); // limpa os espaços inuteis ao redor das palavras
	val = ft_strtrim_spaces(raw[1]);
	free(raw[0]);
	free(raw[1]); // free em ambos
	if (!key || !val || !key[0] || !val[0])
		return (free(key), free(val), 0);
	dict[*idx].key = key; // guarda os ponteiros das strings limpas
	dict[*idx].value = val;
	(*idx)++;
	return (1);
}

// varre a linha inteira. Se achar um :, ele salva a posição na variaval colon.
static int	parse_line(char *line, t_dict *dict, int *idx)
{
	int	colon;
	int	i;

	colon = -1;
	i = -1;
	while (line[++i])
	{
		if (line[i] == ':')
		{
			if (colon != -1)
				return (0);
			colon = i;
		}
	}
	if (colon == -1)
		return (0);
	return (parse_line_values(line, dict, idx, colon));
}


// anda pelo conteudo do dicionario caractere por caractere
// até bater no \n, ai ele manda o ft_substr fazer uma copia exata
// de tudo o que ficou para trás até o início daquela linha
int	fill_dict(char *content, t_dict *dict)
{
	int		s; // start
	int		e; // end
	int		idx;
	char	*line;

	s = 0;
	idx = 0;
	while (content[s])
	{
		e = s;
		while (content[e] && content[e] != '\n')
			e++;
		if (e > s)
		{
			line = ft_substr(content, s, e - s);
			if (!line || !parse_line(line, dict, &idx))
				return (free(line), 0);
			free(line);
		}
		if (!content[e])
			break ;
		s = e + 1;
	}
	return (idx);
}

t_dict	*parse_dict(char *content, int *size)
{
	t_dict	*dict;
	int		real_sz;

	*size = count_valid_lines(content); // descobrir quantas linhas úteis existem no arquivo de texto, e guarda no *size
	if (*size <= 0)
		return (NULL);
	dict = (t_dict *)malloc(sizeof(t_dict) * (*size)); // aloca a memoria exata para guardar todas as structs juntas.
	if (!dict)
		return (NULL);
	real_sz = fill_dict(content, dict); // ler o texto e preencher as "mochilas". Essa função guarda o número real dos itens inseridos em real_sz
	if (!real_sz)
		return (free_dict(dict, *size), (void *)0);
	*size = real_sz;
	if (!has_required_basic_keys(dict, *size)) // se o dicionario nao tiver o "0", "1", "10", etc.., ela aciona o free_dict par jogar tudo no lixo e retornar erro
		return (free_dict(dict, *size), (void *)0);
	return (dict);
}
