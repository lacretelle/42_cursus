/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:04:05 by madufour          #+#    #+#             */
/*   Updated: 2019/02/28 15:33:10 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_tabmap	**fd_error_tab(t_tabmap **tab, char **lines)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	if (lines)
		fd_delete((void***)&lines);
	ft_putendl("Wrong map. Exiting.");
	return (NULL);
}

static t_tabmap	**fd_fill_tab(int x, char *map, int y, int hexa)
{
	char		**lines;
	t_tabmap	**tab;

	if (!(tab = (t_tabmap**)malloc(sizeof(t_tabmap*) * (y + 1))))
		return (NULL);
	tab[y] = 0;
	if (!(lines = ft_strsplit(map, '\n')))
		return (fd_error_tab(tab, lines));
	if (hexa > 0)
	{
		if (!(fd_manage_hexa(lines, x, tab)))
			return (fd_error_tab(tab, lines));
	}
	else
	{
		if (!(fd_map_classic(lines, x, y, tab)))
			return (fd_error_tab(tab, lines));
	}
	fd_delete((void***)&lines);
	return (tab);
}

static t_tabmap	**fd_error(char *map)
{
	if ((map))
		ft_strdel(&map);
	return (NULL);
}

t_tabmap		**fd_read(int fd, int *x, int *y)
{
	char		*line;
	t_tabmap	**tab;
	char		*map;
	char		*tmp;
	int			hexa;

	*y = 0;
	hexa = -1;
	if (!(map = ft_strnew(0)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		*y += 1;
		tmp = ft_strjoin_free(map, line);
		ft_strdel(&line);
		map = ft_strjoin_free(tmp, "\n");
	}
	if ((*x = fd_check(*y, map, &hexa)) < 0)
		return (fd_error(map));
	if (!(tab = fd_fill_tab(*x, map, *y, hexa)))
		return (fd_error(map));
	ft_strdel(&map);
	return (tab);
}
