/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:28:45 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/15 14:31:11 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"


// Esta função só é chamado quando a "caixa" atual de memória está
// prestes a transbordar.
// Ela precisa providenciar uma caixa maior, sem perder os dados.
static int	grow_buffer(t_buf *buf)
{
	char	*new_data;
	int		i;

	buf->cap *= 2; // dobra a capacidade (ex: de 1024 vai para 2048)
	new_data = (char *)malloc(buf->cap); // aluga uma nova caixa gigante no Heap, se falhar, retorna 0
	if (!new_data)
		return (0);
	// esse loop copia letra por letra do buf->data antigo para o new data.
	while (i < buf->len) 
	i = 0;
	{
		new_data[i] = buf->data[i];
		i++;
	}
	free(buf->data); // joga a caixa de 1024 bytes velha no lixo do sistema
	buf->data = new_data; // atualiza o ponteiro da mochila. Agora, a mochla lá no read_file aponta para a caixa gigante nova
	return (1);
}

static char	*finalize_read(t_buf *buf, int fd)
{
	close(fd); // devolve o file descriptor para o SO, o arquivo está lido e fechado.
	if (buf->len + 1 >= buf->cap && !grow_buffer(buf))
	{
		free(buf->data);
		return (NULL);
	}
	buf->data[buf->len] = '\0';
	return (buf->data);
}

char	*read_file(char *filename)
{
	int		fd;
	int		bytes;
	t_buf	buf;

	// aqui usamos buf.cap pois t_buf buf é o dono da struct]
	// no de cima, usamos buf->cap pois só temos o endereço (ponteiro) de outra "pessoa"

	fd = open(filename, O_RDONLY); // indicando que quero abrir o arquivo para apenas leitura
	if (fd < 0) // se o arquivo não existir ou não tiver permissão
		return (NULL);
	buf.cap = 1024; // capacidade inicial para 1024 letras
	buf.len = 0; // começa em 0 pq nada foi lido ainda
	buf.data = (char *)malloc(buf.cap); // pede a caixa no heap (aloca memoria)
	if (!buf.data)
		return (close(fd), (void *)0); // fechando o dict
	bytes = 1;
	while (bytes > 0)
	{
		if (buf.len + 512 >= buf.cap && !grow_buffer(&buf))
			return (close(fd), free(buf.data), (void *)0);
		bytes = read(fd, buf.data + buf.len, 512); // ler deslocando o "cursor" de gravação para o fim da string autal
		if (bytes < 0)
			return (close(fd), free(buf.data), (void *)0);
		buf.len += bytes; // atualiza a "mochila" com a quantidade exatas de letras que acabaram de entrar
	}
	return (finalize_read(&buf, fd));
}
