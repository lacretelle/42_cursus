/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:05:17 by madufour          #+#    #+#             */
/*   Updated: 2018/12/19 17:29:55 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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

int	ft_check_tetri(char *s, int j, int i, int *d)
{
	int	diese;

	diese = *d;
	if (j % 5 == 0 && (s[i] == '\n' || s[i] == '\0'))
	{
		if (diese != 4)
			return (0);
		diese = 0;
		j++;
		i++;
	}
	*d = diese;
	return (1);
}

int	check_char(char *s, int nbl)
{
	int i;
	int j;
	int diese;

	i = 0;
	j = 1;
	diese = 0;
	while (j < nbl + 1)
	{
		while (s[i] != '\n' && s[i] != '\0')
		{
			if ((ft_check_c(s, i, &diese)) == 0)
				return (0);
			i++;
		}
		i++;
		j++;
		if (ft_check_tetri(s, j, i, &diese) == 0)
			return (0);
	}
	return (1);
}
