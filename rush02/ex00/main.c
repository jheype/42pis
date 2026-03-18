/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pea <joaopedroa2707@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:33:56 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/15 18:24:43 by joao-pea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	print_err(char *msg)
{
	write(1, msg, ft_strlen(msg));
	return (1);
}


// essa função preapara o número final e chama a lógica de conversão real.
static int	run_conversion(t_dict *dict, int size, char *num, t_lang lang)
{
	char	*norm;

	if (ft_strcmp(num, "-") == 0) // se o numero for identico a "-" entra em modo stdin
	{
		process_stdin_mode(dict, size, lang);
		return (0);
	}
	if (!is_valid_number(num)) // verifica se o número é valido
		return (print_err("Error\n"));
	norm = normalize_number(num); // normaliza os numeros (remover zeros à esquerda inúteis)
	if (!norm)
		return (print_err("Error\n"));
	if (!convert_number(dict, size, norm, lang)) // tenta converter o número usando o convert_number
		print_err("Dict Error\n");
	else
		write(1, "\n", 1);
	free(norm); // libera memoria
	return (0);
}


// o papel desta função é abrir o dicionario, transformar o texto em algo que o C entenda (uma estrutura de dados)
// executar a conversão e depois limpar (liberar memória).
static int	load_and_run(char *dict_file, char *num)
{
	char	*content;
	t_dict	*dict;
	int		size;
	int		ret;

	content = read_file(dict_file); // chama read_file para ler todo o conteudo do arquivo .dcit e salvar na string content
	if (!content) // se der errado, print erro
		return (print_err("Dict Error\n"));
	dict = parse_dict(content, &size); // se der certo, chama parse_dict para transformar o texto bruto em um array de estruturas t_dict.
	free(content); // aqui liberamos a memoria
	if (!dict)
		return (print_err("Dict Error\n"));
	ret = run_conversion(dict, size, num, detect_lang(dict, size)); //se o dict for válido, detecta o idioma (detect_lang) e chama a função run_conversion
	free_dict(dict, size); // libera memoria
	return (ret);
}

int	main(int argc, char **argv)
{
	char	*dict_f; // nome do arquivo do dicionario
	char	*num; // numero a ser convertido

	dict_f = "numbers.dict"; // dicionario padrão
	if (argc == 2) // se argc for igual a 2, significa que apenas o numero esta sendo passado
		num = argv[1]; // por logica, o numero é o argv 1
	else if (argc == 3) // se caso passe 3, o usuario esta passando um dicionario e o numero
	{
		dict_f = argv[1]; // logicamente, o dicionario é o primeiro argumento
		num = argv[2]; // e o numero é o segundo argumento.
	}
	else
		return (print_err("Error\n")); // se não for nenhum dos dois acima, printa erro
	return (load_and_run(dict_f, num)); // aqui ele passa para o load_and_run lá em cima
}
