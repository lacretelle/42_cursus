/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:48:20 by brobson           #+#    #+#             */
/*   Updated: 2019/01/08 16:05:43 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	set_to_zero(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

int		split_tetri(char *s)
{
	int		i;
	int		nb_d;
	int		nb_v;
	int		nb_l;

	i = 0;
	nb_d = 0;
	nb_v = 0;
	nb_l = 1;
	while (s[i] != '\0')
	{
		if (nb_l == 5)
			nb_l = 1;
		if (s[i] == '#')
			nb_v += neighbour(nb_l, s, i, &nb_d);
		if (s[i] == '\n' && s[i - 1] != '\n')
			nb_l++;
		if (nb_d == 4 && nb_v < 6)
			return (0);
		if (nb_d == 4 && nb_v >= 6)
			set_to_zero(&nb_d, &nb_v);
		i++;
	}
	return (1);
}
