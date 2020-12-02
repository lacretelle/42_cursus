/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 10:54:39 by brobson           #+#    #+#             */
/*   Updated: 2019/01/10 10:29:39 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char	**ft_fill_tab(char *s, int nb, char **tab)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 65;
	while (i < nb)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * (17))))
		{
			ft_del((void***)&tab);
			return (NULL);
		}
		tab[i][16] = '\0';
		if (!(tab[i] = ft_fill_tetri(s, tab[i], &j, c)))
		{
			ft_del((void***)&tab);
			return (NULL);
		}
		i++;
		c++;
	}
	return (tab);
}

char		**tetriminos(char *s, int nbtetri)
{
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * (nbtetri + 1))))
		return (NULL);
	tab[nbtetri] = 0;
	if (!(tab = ft_fill_tab(s, nbtetri, tab)))
	{
		ft_del((void***)&tab);
		return (NULL);
	}
	return (tab);
}
