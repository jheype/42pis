/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:33:56 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/15 15:08:06 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	print_err(char *msg)
{
	write(1, msg, ft_strlen(msg));
	return (1);
}

static int	run_conversion(t_dict *dict, int size, char *num, t_lang lang)
{
	char	*norm;

	if (ft_strcmp(num, "-") == 0)
	{
		process_stdin_mode(dict, size, lang);
		return (0);
	}
	if (!is_valid_number(num))
		return (print_err("Error\n"));
	norm = normalize_number(num);
	if (!norm)
		return (print_err("Error\n"));
	if (!convert_number(dict, size, norm, lang))
		print_err("Dict Error\n");
	else
		write(1, "\n", 1);
	free(norm);
	return (0);
}

static int	load_and_run(char *dict_file, char *num)
{
	char	*content;
	t_dict	*dict;
	int		size;
	int		ret;

	content = read_file(dict_file);
	if (!content)
		return (print_err("Dict Error\n"));
	dict = parse_dict(content, &size);
	free(content);
	if (!dict)
		return (print_err("Dict Error\n"));
	ret = run_conversion(dict, size, num, detect_lang(dict, size));
	free_dict(dict, size);
	return (ret);
}

int	main(int argc, char **argv)
{
	char	*dict_f;
	char	*num;

	dict_f = "numbers.dict";
	if (argc == 2)
		num = argv[1];
	else if (argc == 3)
	{
		dict_f = argv[1];
		num = argv[2];
	}
	else
		return (print_err("Error\n"));
	return (load_and_run(dict_f, num));
}
