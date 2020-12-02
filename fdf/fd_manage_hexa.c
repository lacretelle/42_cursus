/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_manage_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:06:09 by madufour          #+#    #+#             */
/*   Updated: 2019/03/02 17:02:17 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fd_iscoma(char *s)
{
	int	i;

	if ((s))
	{
		i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == ',')
				return (1);
			i++;
		}
	}
	return (0);
}

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

static t_tabmap	*fd_fill_hexa(t_tabmap *tab, char *s, int i)
{
	int		coma;
	char	**tmp;

	coma = fd_iscoma(s);
	if (coma == 1)
	{
		if (!(tmp = ft_strsplit(s, ',')))
			return (NULL);
		if ((tab[i].color = fd_atoi_hexa(tmp[1])) < 0
				|| (fd_check_map(tmp[0]) < 0))
		{
			fd_delete((void***)&tmp);
			return (NULL);
		}
		tab[i].p = ft_atoi(tmp[0]);
		fd_delete((void***)&tmp);
	}
	else
	{
		if (fd_check_map(s) < 0)
			return (NULL);
		tab[i].color = 0;
		tab[i].p = ft_atoi(s);
	}
	return (tab);
}

static t_tabmap	*fd_create_tab(char **s, int x)
{
	t_tabmap	*tab;
	int			i;

	i = 0;
	if (!(tab = (t_tabmap*)malloc(sizeof(t_tabmap) * x)))
		return (NULL);
	while (s[i] && i < x)
	{
		if (!(fd_fill_hexa(tab, s[i], i)))
		{
			free(tab);
			return (NULL);
		}
		i++;
	}
	return (tab);
}

t_tabmap		**fd_manage_hexa(char **lines, int x, t_tabmap **tab)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = 0;
	while (lines[i] != 0)
	{
		if (!(tmp = ft_strsplit(lines[i], ' ')))
			return (NULL);
		if (!(tab[i] = fd_create_tab(tmp, x)))
		{
			fd_delete((void***)&tmp);
			return (NULL);
		}
		fd_delete((void***)&tmp);
		i++;
	}
	return (tab);
}
