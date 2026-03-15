/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:30:12 by jode-alm          #+#    #+#             */
/*   Updated: 2026/02/28 14:42:38 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
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

    if (ft_str_is_lowercase(str))
        printf("Resultado: 1 (Apenas letras minusculas)\n");
    else
        printf("Resultado: 0 (Contem outros caracteres)\n");

    return (0);
}*/
