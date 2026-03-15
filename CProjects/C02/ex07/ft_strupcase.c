/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:56:57 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/02 17:45:29 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

/*int main(void)
{
    char str1[] = "hello world";
    char str2[] = "123! @abc#";
    char str3[] = "JÁ ESTÁ ALTO";
    char str4[] = "";

    printf("--- Testando ft_strupcase ---\n\n");

    printf("Original 1: hello world\n");
    printf("Resultado 1: %s\n\n", ft_strupcase(str1));

    printf("Original 2: 123! @abc#\n");
    printf("Resultado 2: %s\n\n", ft_strupcase(str2));

    printf("Original 3: JÁ ESTÁ ALTO\n");
    printf("Resultado 3: %s\n\n", ft_strupcase(str3));

    printf("Original 4: (vazio)\n");
    printf("Resultado 4: [%s]\n", ft_strupcase(str4));

    return (0);
}*/
