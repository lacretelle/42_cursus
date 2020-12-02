/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:06:10 by madufour          #+#    #+#             */
/*   Updated: 2019/02/25 14:34:18 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fd_def_m(t_mlx mlx, int diff, int x, int y)
{
	int	m;

	if (mlx.map.tab[y][x].p < (int)diff)
		m = 1;
	else if (mlx.map.tab[y][x].p < (int)(2 * diff))
		m = 2;
	else if (mlx.map.tab[y][x].p < (int)(3 * diff))
		m = 3;
	else if (mlx.map.tab[y][x].p < (int)(4 * diff))
		m = 4;
	else
		m = 5;
	return (m);
}

static int	fd_define_color(t_mlx mlx, int x, int y)
{
	double	diff;
	int		m;
	int		color;

	diff = mlx.map.max - mlx.map.min;
	if (diff < 0)
		diff *= -1;
	diff /= 5;
	m = fd_def_m(mlx, diff, x, y);
	if (mlx.conf.color == 0xff0000)
		color = fd_deg_color('r', m);
	if (mlx.conf.color == 0xff00)
		color = fd_deg_color('g', m);
	if (mlx.conf.color == 0xff)
		color = fd_deg_color('b', m);
	if (mlx.conf.color == 0xffffff)
		color = fd_deg_color('a', m);
	return (color);
}

static int	fd_basic_color(t_mlx mlx, int x, int y, int n)
{
	int color;

	if (mlx.map.tab[y][x].p < 0)
		color = 0x000000ff;
	else if (mlx.map.tab[y][x].p >= 0 && mlx.map.tab[y][x].p < n)
		color = 0x0000ff00;
	else if (mlx.map.tab[y][x].p >= n && mlx.map.tab[y][x].p < (2 * n))
		color = 0x007e5835;
	else
		color = 0x00ffffff;
	return (color);
}

int			fd_color(t_mlx mlx, int x, int y)
{
	int		n;
	int		color;

	n = (int)(mlx.map.max / 3);
	if (mlx.map.tab[y][x].color != 0)
	{
		if (mlx.conf.color != 0x0048d1cc)
			color = fd_define_color(mlx, x, y);
		else
			color = mlx.map.tab[y][x].color;
	}
	else
	{
		if (mlx.conf.color != 0x0048d1cc)
			color = fd_define_color(mlx, x, y);
		else
			color = fd_basic_color(mlx, x, y, n);
	}
	return (color);
}
