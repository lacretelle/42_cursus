/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:49:10 by madufour          #+#    #+#             */
/*   Updated: 2019/01/10 11:54:39 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	ft_find_nbl(int p, int sqr)
{
	int nbl;

	if (p >= 0 && p < sqr)
		nbl = 0;
	else
		nbl = p / sqr;
	return (nbl);
}

static int	check_place(char *map, int *p, char *tetri, int sqr)
{
	int j;
	int letter;
	int i;
	int k;

	j = 0;
	i = 0;
	letter = 0;
	k = 0;
	j = *p % sqr;
	while (j < sqr && i < 4)
	{
		if (tetri[i] != '.' && map[*p + k] != '.')
			return (-1);
		else if (tetri[i] != '.' && map[*p + k] == '.')
			letter++;
		i++;
		j++;
		k++;
	}
	*p += sqr;
	return (letter);
}

static int	ft_valide(int letter, int ***tab, int nbl)
{
	int **coor;

	coor = *tab;
	if (letter < 0 || letter != coor[nbl][0])
	{
		ft_del((void***)&coor);
		return (0);
	}
	return (1);
}

int			ft_test_place(char *map, char *tetri, int sqr, int p)
{
	int	**coor;
	int	nbl;
	int letter;
	int tot_letter;

	tot_letter = 0;
	nbl = 0;
	if ((coor = ft_tab_coord(tetri)) == 0 || (map[p] != '.' && tetri[0] != '.'))
	{
		if ((coor))
			ft_del((void***)&coor);
		return (0);
	}
	while (nbl < 4 && p < sqr * sqr)
	{
		letter = check_place(map, &p, tetri + (nbl * 4), sqr);
		if (ft_valide(letter, &coor, nbl) == 0)
			return (0);
		nbl++;
		tot_letter += letter;
	}
	ft_del((void***)&coor);
	if (tot_letter != 4)
		return (0);
	return (1);
}
