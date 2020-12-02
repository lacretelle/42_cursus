/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:07:36 by brobson           #+#    #+#             */
/*   Updated: 2019/01/08 16:07:41 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	ft_place_line(char *map, char *tetri, int p, int sqr)
{
	int i;
	int j;
	int letter;

	i = 0;
	letter = 0;
	j = p % sqr;
	while (j < sqr && i < 4)
	{
		if (tetri[i] != '.' && map[p] == '.')
		{
			map[p] = tetri[i];
			letter++;
		}
		i++;
		j++;
		p++;
	}
	return (letter);
}

static void	ft_place(char *tetri, char *map, int p, int sqr)
{
	int j;
	int	i;
	int nbl;
	int	letter;

	letter = 0;
	i = 0;
	if (p >= 0 && p < sqr)
		nbl = 0;
	else
		nbl = p / sqr;
	j = p % sqr;
	while (letter < 4 && nbl < sqr && p < sqr * sqr)
	{
		letter += ft_place_line(map, tetri + (i * 4), p, sqr);
		nbl++;
		i++;
		p = j + sqr * nbl;
	}
}

static int	ft_clean_map(char *map, char **tetri, int i, int sqr)
{
	int		p;
	int		j;
	int		letter;
	char	c;

	letter = 0;
	p = 0;
	j = 0;
	while (tetri[i][j] == '.')
		j++;
	c = tetri[i][j];
	while (p < sqr * sqr && letter != 4)
	{
		if (map[p] == c)
		{
			map[p] = '.';
			letter++;
		}
		p++;
		if (letter == 4)
			return (1);
	}
	return (0);
}

int			ft_algo(char *map, int sqr, char **tetri, int i)
{
	int p;

	p = 0;
	if (tetri[i] == 0)
		return (1);
	while (p < sqr * sqr)
	{
		if ((ft_test_place(map, tetri[i], sqr, p)))
		{
			ft_place(tetri[i], map, p, sqr);
			if ((ft_algo(map, sqr, tetri, i + 1)))
				return (1);
		}
		p++;
	}
	if (i > 0)
		ft_clean_map(map, tetri, i - 1, sqr);
	return (0);
}
