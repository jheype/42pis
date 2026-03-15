/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:17:21 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/04 15:59:16 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

/*int	main(void)
{
    char str[40];

    printf("Digite algo: ");
    scanf("%s", str);

    if (ft_str_is_numeric(str))
        printf("Resultado: 1 (Apenas digitos)\n");
    else
        printf("Resultado: 0 (Contem outros caracteres)\n");

    return (0);
}*/
