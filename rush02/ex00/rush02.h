/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:10:08 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/15 15:13:10 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef enum e_lang
{
	LANG_EN,
	LANG_PT,
	LANG_FR
}	t_lang;

typedef struct s_dict
{
	char	*key;
	char	*value;
	t_lang	lang;
}	t_dict;

typedef struct s_buf
{
	char	*data;
	int		len;
	int		cap;
}	t_buf;

typedef struct s_convert_ctx
{
	int		groups;
	int		first_len;
	int		i;
	int		start;
	int		first;
	t_lang	lang;
	char	*num;
}	t_convert_ctx;

typedef struct s_chunk_ctx
{
	int		*first;
	t_lang	lang;
}	t_chunk_ctx;

int			main(int argc, char **argv);
int			is_valid_number(char *str);
char		*normalize_number(char *str);
char		*read_file(char *filename);
t_dict		*parse_dict(char *content, int *size);
int			count_valid_lines(char *content);
char		*dict_get_value(t_dict *dict, int size, char *key);
int			has_required_basic_keys(t_dict *dict, int size);
t_lang		detect_lang(t_dict *dict, int size);
void		free_dict(t_dict *dict, int size);
char		*make_scale_key(int group_index);
int			is_chunk_zero(char *chunk);
char		*chunk_from_number(char *num, int start, int len);
int			group_count(char *num);
int			has_nonzero_group_after(char *num, int current_group,
				int groups, int first_len);
int			get_chunk_len(t_convert_ctx *ctx);
void		init_ctx(t_convert_ctx *ctx, char *num, t_lang lang);
int			process_nonzero_chunk(t_dict *dict, int size,
				char *chunk, t_convert_ctx *ctx);
int			convert_number(t_dict *dict, int size, char *num, t_lang lang);
void		print_word(char *word, int *first);
void		print_sep(char *sep);
int			print_units(t_dict *dict, int size, char c, int *first);
int			print_units_compact(t_dict *dict, int size, char c, int *first);
int			print_teens(t_dict *dict, int size, char *two, int *first);
int			print_tens_and_units_en(t_dict *dict, int size,
				char *two, int *first);
int			print_tens_and_units_pt(t_dict *dict, int size,
				char *two, int *first);
int			print_tens_and_units_fr(t_dict *dict, int size,
				char *two, int *first);
char		*get_hundred_word(t_dict *dict, int size, char *chunk);
int			convert_chunk(t_dict *dict, int size, char *chunk,
				t_chunk_ctx *cctx);
char		*read_stdin_line(void);
int			process_stdin_mode(t_dict *dict, int size, t_lang lang);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, int n);
char		*ft_strdup(char *src);
char		*ft_substr(char *src, int start, int len);
char		*ft_strtrim_spaces(char *str);
char		*ft_strjoin_free(char *s1, char *s2);
int			ft_is_space(char c);
int			ft_is_digit(char c);

#endif