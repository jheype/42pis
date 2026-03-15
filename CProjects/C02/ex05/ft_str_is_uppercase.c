/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:43:07 by jode-alm          #+#    #+#             */
/*   Updated: 2026/02/28 14:46:39 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

/*int main(void)
{
    char str[40];

    printf("Digite algo: ");
    scanf("%s", str);

    if (ft_str_is_uppercase(str))
        printf("Resultado: 1 (Apenas letras maiusculas)\n");
    else
        printf("Resultado: 0 (Contem outros caracteres)\n");

    return (0);
}*/
