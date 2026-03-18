/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 12:27:23 by wgolbert          #+#    #+#             */
/*   Updated: 2026/03/15 12:27:26 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"


// expansor de memoria
// caso o usuario coloque um numero grande demais, nós alocamos outro espaço na memoria
// pegamos tudo que encheu quando o usuario digitou o numero, e passamos para o
// novo espaço na memória e jogamos o espaço antigo fora
// RESUMO: pega uma string que encheu, cria uma maior, copia os dados e a apaga a antiga.
static int	grow_line_buffer(char **buf, int *cap) // ponteiro para ponteiro do buffer original, porque ela precisa alterar o ENDEREÇO de memória que a variável buf aponta na função que a chamou.
{
	char	*new_buf;
	int		i;
	int		old_cap;

	old_cap = *cap; // salvando o tamanho antigo de cap em old_cap (ex: 64)
	*cap *= 2; // dobra a capacidade (pega a atual e multiplica por 2) (ex: 64 * 2)
	new_buf = (char *)malloc(*cap); // pedindo 128 bytes contiguos na memoria Heap, então o sistema devolve o endereço do primeiro byte desse bloco. o (char *) é um cast, apenas para garantir que o C trate esse bloco genérico como um array de caracteres
	if (!new_buf) // verifica se o computador esta sem memoria ram e retorna false
		return (0);
	i = 0;
	while (i < old_cap) // enquanto o indice for menor que o tamanho antigo (64 bytes)
	{
		new_buf[i] = (*buf)[i]; // passa tudo que tinha antes, para o buf novo
		i++;
	}
	free(*buf); // devolvemos o bloco antigo (de 64 bytes)
	*buf = new_buf; // faz o ponteiro original apontar para a caixa nova de 128 bytes
	return (1); // retorna true dizendo que a expansão deu certo
}

// lê o que o usuario digita
char	*read_stdin_line(void)
{
	char	c;
	char	*buf;
	int		cap;
	int		len;
	int		bytes;

	cap = 64; // define a capacidade inicial para 64 bytes
	len = 0; // o tamanho preenchido (len) para 0
	buf = (char *)malloc(cap); // malloc inicial. Se falhar, retorna NULL e encerra
	if (!buf)
		return (NULL);
	bytes = read(0, &c, 1); // lê do file descriptor 0 (teclado/stdin), guarda na variavel c e lê 1 byte por vez.
	while (bytes > 0) // enquanto conseguir ler algo, entra no loop
	{
		if (c == '\n') // se for um enter, da um break e sai do loop.
			break ;
		// matematica de expansão:
		// veirica se len + 1 >= cap. Por que o +1? pra garantir que sobra espaço vazio
		// para o caractere nulo '\0' depois que o loop acabar.
		// se o tamanho estiver no limite, ele chama o grow_line_buffer
		if (len + 1 >= cap && !grow_line_buffer(&buf, &cap))
			return (free(buf), NULL); // economia de linha, O C avalia as expressões separadas por virgula da esquerda para a direita e retorna a ultima, então ele da free(buf) e depois retorna NULL
		buf[len++] = c; // guarda a letra no buffer e já soma 1 no len (len++)
		bytes = read(0, &c, 1); // lê a próxima letra para avliar na próxima volta do loop while
	}
	if (bytes <= 0 && len == 0)
		return (free(buf), NULL); // se o read não leu nada e o buffer esta vazio, libera o buffer e retorna null.
	buf[len] = '\0'; // fecha a string com o caractere nulo
	return (buf); // retorna a string pronta
}

int	process_stdin_mode(t_dict *dict, int size, t_lang lang)
{
	char	*line; // guarda o que o usuário digitou
	char	*norm; // guarda o numero limpo (ex: depois de transformar "0042" em "42")

	line = read_stdin_line(); // chama a função anterior
	while (line)
	{
		if (!is_valid_number(line)) // verifica se a string é apenas números
			ft_putstr("Error\n");
		else
		{
			norm = normalize_number(line); // chamando o normalize_number, que cria uma nova string na memoria (usando outro malloc lá dentro) com o numero formatado direitnho e devolve o endereço dessa nova string para a variavel norm
			if (!norm || !convert_number(dict, size, norm, lang))
				ft_putstr("Dict Error\n");
			else
				ft_putstr("\n");
			free(norm); // devolvendo o norm apois usala
		}
		free(line); // devolvendo a string que foi lida no iniicio da função
		line = read_stdin_line(); // reinicia.
	}
	return (1);
}
