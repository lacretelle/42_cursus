/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:00:44 by madufour          #+#    #+#             */
/*   Updated: 2018/12/14 16:54:13 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
char	*ft_algo(char *map, int sqr, char **tetri, int i);

//APPELER PAR SOLVE et APPPEEELLLLE ---> RESOLVE

static int	ft_sq_min(int nbTetri)
{
	int	nb;
	int	sqrt;

	sqrt = 1;
	nb = nbTetri * 4;
	while (sqrt < 12 && (sqrt * sqrt) < nb)
	{
		if ((sqrt * sqrt) == nb)
			return (sqrt);
		sqrt++;
	}
	return (sqrt);
}

static char	*ft_create_map(int	sq)
{
	char	*map;
	int		i;

	i = 0;
	if(!(map = ft_strnew((sq * sq) - 1)))
		return (NULL);
	while (i < (sq * sq))
	{
		map[i] = '.';
		i++;
	}
	return (map);
}
static int	ft_place_first(char *tetri, char *map, int cursor)
{
	int	i;

	i = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] >= 65 && tetri[i] <= 90)
			map[cursor] = tetri[i];
		i++;
		cursor++;
	}
	return (1);
}
//gestion de la map en foction de la solution 

char		*ft_resolve(int nbTetri, char **tetri)
{
	char	*map;
	int		sq_min;

	sq_min = ft_sq_min(nbTetri);//ok
	map = ft_create_map(sq_min);//MALLOC DE LA MAP (OK)
    while (!(ft_algo(map, sq_min, tetri, 0)))
    {
        sq_min++;
        free(map);
	    map = ft_create_map(sq_min);//MALLOC PROTECT
    }
    return (map);
}

