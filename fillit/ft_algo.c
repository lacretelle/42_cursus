/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:42:30 by madufour          #+#    #+#             */
/*   Updated: 2018/12/14 17:32:46 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//APPELLER PAR MAP : --> MAP, char **tetri

static int  ft_test_place(char *map, char *tetri, int max, int p)
{
    int i;
    int letter;

    i = 0;
    letter = 0;
    while (p < max && tetri[i] != '\0')
    {
        if (tetri[i] != '.' && map[p] != '.')
            return (0);
        else if (tetri[i] != '.' && map[p] == '.')
            letter += 1;
        i++;
        p++;
        if (letter == 4)
            return (1);
    }
    return (0);
}

static void	ft_place(char *tetri, char *map, int p, int max)
{
	int	i;
	int	letter;

	i = 0;
	letter = 0;
	while (tetri[i] != '\0' && p < max && letter < 4)
	{
		if (tetri[i] != '.' && map[p] == '.')
		{
			map[p] = tetri[i];
			letter++;
		}
		i++;
		p++;
	}
}

static int  ft_clean_map(char *map, int max, char *tetri)
{
    int p;
    int i;
    int letter;

    i = 0;
    letter = 0;
    while (tetri[i] != '\0' && letter < 4)
    {
        if (tetri[i] != '.')
        {
            while (map[p] != tetri[i])
                p++;
            map[p] = '.';
            p++;
            i++;
            letter++;
        }
        i++;
        if (letter == 4)
            return (1);
    }
    return (0);
}

int     	ft_algo(char *map, int sqr, char **tetri, int i)
{
    int p;
    int max;

    p = 0;
    max = sqr * sqr;
    if (tetri[i] == 0)
        return (1);
    while (p < max)
    {
        if ((ft_test_place(map, tetri[i], max, p)))
        {
            ft_place(tetri[i], map, p, max);
            if ((ft_algo(map, sqr, tetri, i + 1)))
                return(1);
        }
        p++;
    }
    if (!(ft_clean_map(map, max, tetri[i - 1])))
        return (0);
    return (0);
}
