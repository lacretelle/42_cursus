/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:02:52 by madufour          #+#    #+#             */
/*   Updated: 2019/01/10 12:01:23 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void	ft_display(char *solution, int sqr)
{
	int i;

	i = 0;
	while (solution[i] != '\0')
	{
		ft_putchar(solution[i]);
		i++;
		if (i % sqr == 0)
			ft_putchar('\n');
	}
}

int			solve(char *s, int nbl)
{
	int		nbtetri;
	char	**tetri;
	char	*solution;
	int		sqr;

	nbtetri = (nbl + 1) / 5;
	sqr = 0;
	if (!(tetri = tetriminos(s, nbtetri)))
		return (0);
	if (!(solution = ft_resolve(nbtetri, tetri, &sqr)))
	{
		ft_del((void***)&tetri);
		return (0);
	}
	ft_display(solution, sqr);
	ft_strdel(&solution);
	ft_del((void***)&tetri);
	return (1);
}
