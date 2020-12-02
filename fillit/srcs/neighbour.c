/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:00:49 by brobson           #+#    #+#             */
/*   Updated: 2019/01/08 16:00:55 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_neighbour_1st_line(char *s, int i)
{
	int		cpt;

	cpt = 0;
	if (i == 0)
	{
		if (s[i + 1] == '#')
			cpt++;
		if (s[i + 5] == '#')
			cpt++;
	}
	else
	{
		if (s[i + 1] == '#')
			cpt++;
		if (s[i + 5] == '#')
			cpt++;
		if (s[i - 1] == '#')
			cpt++;
	}
	return (cpt);
}

int		check_neighbour(char *s, int i)
{
	int		cpt;

	cpt = 0;
	if (s[i + 1] == '#')
		cpt++;
	if (s[i + 5] == '#')
		cpt++;
	if (s[i - 1] == '#')
		cpt++;
	if (s[i - 5] == '#')
		cpt++;
	return (cpt);
}

int		check_neighbour_last_line(char *s, int i)
{
	int		cpt;

	cpt = 0;
	if (s[i + 1] == '#')
		cpt++;
	if (s[i - 1] == '#')
		cpt++;
	if (s[i - 5] == '#')
		cpt++;
	return (cpt);
}

int		neighbour(int nb_l, char *s, int i, int *nb_d)
{
	*nb_d = *nb_d + 1;
	if (nb_l == 1)
		return (check_neighbour_1st_line(s, i));
	else if (nb_l == 4)
		return (check_neighbour_last_line(s, i));
	else
		return (check_neighbour(s, i));
}
