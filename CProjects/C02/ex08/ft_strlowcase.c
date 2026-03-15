/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:28:36 by jode-alm          #+#    #+#             */
/*   Updated: 2026/02/28 15:35:56 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

/*int main(void)
{
    // Casos de teste
    char str1[] = "HELLO WORLD";
    char str2[] = "123! @ABC#";
    char str3[] = "ja esta baixo";
    char str4[] = "";

    printf("--- Testando ft_strlowcase ---\n\n");

    printf("Original 1: HELLO WORLD\n");
    printf("Resultado 1: %s\n\n", ft_strlowcase(str1));

    printf("Original 2: 123! @ABC#\n");
    printf("Resultado 2: %s\n\n", ft_strlowcase(str2));

    printf("Original 3: ja esta baixo\n");
    printf("Resultado 3: %s\n\n", ft_strlowcase(str3));

    printf("Original 4: (vazio)\n");
    printf("Resultado 4: [%s]\n", ft_strlowcase(str4));

    return (0);
}*/
