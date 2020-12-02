/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:27:51 by madufour          #+#    #+#             */
/*   Updated: 2019/01/10 10:28:28 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	ft_sq_min(int nbtetri)
{
	int	nb;
	int	sqrt;

	sqrt = 1;
	nb = nbtetri * 4;
	while (sqrt < 12 && (sqrt * sqrt) < nb)
	{
		if ((sqrt * sqrt) == nb)
			return (sqrt);
		sqrt++;
	}
	return (sqrt);
}

static char	*ft_create_map(int sq)
{
	char	*map;
	int		i;

	i = 0;
	if (!(map = ft_strnew(sq * sq)))
		return (NULL);
	map[sq * sq] = '\0';
	while (i < sq * sq)
	{
		map[i] = '.';
		i++;
	}
	return (map);
}

char		*ft_resolve(int nbtetri, char **tetri, int *sq)
{
	char	*map;
	int		sq_min;

	sq_min = ft_sq_min(nbtetri);
	if (!(map = ft_create_map(sq_min)))
		return (NULL);
	while (!(ft_algo(map, sq_min, tetri, 0)))
	{
		ft_strdel(&map);
		sq_min++;
		if (!(map = ft_create_map(sq_min)))
			return (NULL);
	}
	*sq = sq_min;
	return (map);
}
