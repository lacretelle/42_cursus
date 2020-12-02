/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:44:29 by madufour          #+#    #+#             */
/*   Updated: 2018/12/12 11:31:14 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_first(char *s, int *j)
{
	if (*j == 0)
	{
		if (s[*j + 1] == '#' || s[*j + 5] == '#')
			return (1);
	}
	else
	{
		if (s[*j + 1] == '#' || s[*j + 5] == '#' || s[*j - 1] == '#')
			return (1);
	}
	return (0);
}

int check_last(char *s, int *j)
{
	if (s[*j - 1] == '#' || s[*j + 1] == '#' || s[*j - 5] == '#')
		return (1);
	return (0);
}

int check_else(char *s, int *j)
{
	if (s[*j - 1] == '#' || s[*j + 1] == '#' || s[*j - 5] == '#' ||
			s[*j + 5] == '#')
		return (1);
	return (0);
}

int	valid_tetris(char *s)
{
	int nbL;
	int i;

	i = 0;
	nbL = 1;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (nbL == 1 && check_first(s, &i) == 0)
				return (0);
			else if (nbL % 4 == 0 && check_last(s, &i) == 0)
				return (0);
			else
			{
				if (check_else(s, &i) == 0)
					return (0);
			}
		}
		i++;
		if (i % 5 == 0)
			nbL++;
	}
	return (1);
}
