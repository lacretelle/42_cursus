/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:24:17 by madufour          #+#    #+#             */
/*   Updated: 2019/01/10 10:27:20 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char	*ft_fill_left(char *tab, int first)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (!(tmp = ft_strdup(tab)))
		return (NULL);
	while (i < 16)
	{
		j = 0;
		while ((j + first) < 4)
		{
			tab[i] = tmp[i + first];
			i++;
			j++;
		}
		while (j < 4)
		{
			tab[i] = '.';
			i++;
			j++;
		}
	}
	free(tmp);
	return (tab);
}

static char	*ft_on_left(char *tab)
{
	int i;
	int j;
	int first;

	i = 0;
	first = 0;
	while (tab[first] == '.')
		first++;
	if (first > 0)
	{
		i = 4;
		while (i < 16)
		{
			if (tab[i] != '.')
			{
				if (i % 4 < first)
					first = i % 4;
			}
			i++;
		}
		if (!(tab = ft_fill_left(tab, first)))
			return (NULL);
	}
	return (tab);
}

static int	ft_fill_line(char *s, char **tmp, int i, int c)
{
	int		k;
	char	*tab;

	tab = *tmp;
	k = 0;
	while (i < 19)
	{
		if (s[i] == '\n')
			i++;
		if (s[i] == '#')
			tab[k] = c;
		else
			tab[k] = s[i];
		i++;
		k++;
	}
	while (k < 16)
		tab[k++] = '.';
	return (i);
}

char		*ft_fill_tetri(char *s, char *tab, int *j, int c)
{
	int	nbl;
	int i;
	int k;

	nbl = 0;
	i = 0;
	while (s[i + *j] != '#')
	{
		if (s[i + *j] == '\n')
			nbl++;
		i++;
	}
	i = nbl * 5;
	k = *j;
	i = ft_fill_line(s + k, &tab, i, c);
	if (!(tab = ft_on_left(tab)))
		return (NULL);
	*j += (i + 2);
	return (tab);
}
