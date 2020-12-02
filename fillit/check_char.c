/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:05:17 by madufour          #+#    #+#             */
/*   Updated: 2018/12/10 18:43:15 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_c(char *s, int j, int *d)
{
	int diese;

	diese = *d;
	if (s[j] != '.' && s[j] != '#')
		return (0);
	if (s[j] == '#')
		diese += 1;
	*d = diese;
	return (1);
}

int	check_char(char *s, int nbL)
{
	int i;
	int j;
	int diese;

	i = 0;
	j = 0;
	while (j < nbL)
	{
		diese = 0;
		while (s[i] != '\n' && s[i] != '\0')
		{
			if ((ft_check_c(s, i, &diese)) == 0)
				return (0);
			i++;
		}
		j++;
		i++;
		if (j % 5 == 0 && s[i] == '\n')
		{
			if (diese != 4)
				return (0);
			j++;
			i++;
		}
	}
	return (1);
}
