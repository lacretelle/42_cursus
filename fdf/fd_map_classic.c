/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_map_classic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:38:19 by madufour          #+#    #+#             */
/*   Updated: 2019/02/28 16:38:12 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fd_check_map(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= 48 && s[i] <= 57) || s[i] == '-')
			i++;
		else
			return (-1);
	}
	return (1);
}

static t_tabmap	*fd_error(t_tabmap *tab, char **s)
{
	if (s)
		fd_delete((void***)&s);
	if (tab)
		free(tab);
	return (NULL);
}

static t_tabmap	*fd_create_tab(char *lines, int size)
{
	int			i;
	t_tabmap	*tab;
	char		**s;

	s = 0;
	if (!(tab = (t_tabmap*)malloc(sizeof(t_tabmap) * size)))
		return (NULL);
	if (!(s = ft_strsplit(lines, ' ')))
		return (fd_error(tab, s));
	i = 0;
	while (s[i] && i < size)
	{
		if (fd_check_map(s[i]) < 0)
			return (fd_error(tab, s));
		tab[i].p = ft_atoi(s[i]);
		tab[i].color = 0;
		i++;
	}
	fd_delete((void***)&s);
	return (tab);
}

t_tabmap		**fd_map_classic(char **lines, int x, int y, t_tabmap **tab)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (!(tab[i] = fd_create_tab(lines[i], x)))
			return (0);
		i++;
	}
	return (tab);
}
