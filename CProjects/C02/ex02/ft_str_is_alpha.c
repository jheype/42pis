/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:32:28 by jode-alm          #+#    #+#             */
/*   Updated: 2026/03/04 16:01:55 by jode-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
		{
			if (!(str[i] >= 'A' && str[i] <= 'Z'))
				return (0);
		}
		i++;
	}
	return (1);
}

/*
  #include <stdio.h>

  int main(void)
{
    char str[40];

    printf("Digite algo: ");
    scanf("%s", str);

    if (ft_str_is_alpha(str))
        printf("Resultado: 1 (Apenas letras)\n");
    else
        printf("Resultado: 0 (Contem outros caracteres)\n");

    return (0);
}*/
