/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tabint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:13:12 by madufour          #+#    #+#             */
/*   Updated: 2019/01/10 11:52:44 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	**ft_create_tab(int **tab)
{
	int nbl;

	nbl = 0;
	while (nbl < 4)
	{
		if (!(tab[nbl] = (int*)malloc(sizeof(int) * 1)))
			return (NULL);
		tab[nbl][0] = 0;
		nbl++;
	}
	return (tab);
}

int			**ft_tab_coord(char *tetri)
{
	int **tab;
	int	nbl;
	int	i;

	i = 0;
	nbl = 0;
	if (!(tab = (int**)malloc(sizeof(int*) * 5)))
		return (NULL);
	tab[4] = 0;
	if (!(tab = ft_create_tab(tab)))
	{
		ft_del((void***)&tab);
		return (NULL);
	}
	while (i < 16)
	{
		if (tetri[i] != '.')
			tab[nbl][0] += 1;
		i++;
		if (i % 4 == 0)
			nbl++;
	}
	return (tab);
}
