/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_coord_euler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:40:23 by madufour          #+#    #+#             */
/*   Updated: 2019/03/01 17:26:36 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fd_manage_euler(t_mlx *mlx, int k)
{
	if (k == 33)
	{
		mlx->conf.angle.teta += 5;
		if (mlx->conf.angle.teta > 360)
			mlx->conf.angle.teta %= 360;
	}
	else if (k == 30)
	{
		mlx->conf.angle.nu += 5;
		if (mlx->conf.angle.nu > 360)
			mlx->conf.angle.nu %= 360;
	}
	else
	{
		mlx->conf.angle.alpha += 5;
		if (mlx->conf.angle.alpha > 360)
			mlx->conf.angle.alpha %= 360;
	}
}

static t_ang	fd_init_ang(t_mlx mlx)
{
	t_ang	m;

	m.a = (mlx.conf.angle.teta * M_PI) / 180;
	m.b = (mlx.conf.angle.nu * M_PI) / 180;
	m.c = (mlx.conf.angle.alpha * M_PI) / 180;
	return (m);
}

static double	fd_rotate_x(int x, int y, t_ang m, int z)
{
	double	n;

	n = (cos(m.c) * cos(m.a) - sin(m.c) * cos(m.b) * sin(m.a)) * (double)x;
	n += ((-1 * sin(m.c) * cos(m.a)) - (cos(m.c) * cos(m.b) *
				sin(m.a))) * (double)y;
	n += (sin(m.b) * sin(m.a)) * (double)z;
	return (n);
}

static double	fd_rotate_y(int x, int y, t_ang m, int z)
{
	double	n;

	n = (cos(m.c) * sin(m.a) + sin(m.c) * cos(m.b) * cos(m.a)) * (double)x;
	n += ((-1 * sin(m.c) * sin(m.a)) + (cos(m.c) * cos(m.b) *
				cos(m.a))) * (double)y;
	n += (-1 * sin(m.b) * cos(m.a)) * (double)z;
	return (n);
}

t_point			fd_coord_euler(t_mlx mlx, int x, int y, int side)
{
	t_ang	m;
	t_point	n;
	int		z;

	m = fd_init_ang(mlx);
	z = mlx.map.tab[y][x].p;
	n.x0 = (int)(fd_rotate_x(x, y, m, z) * (double)mlx.conf.between)
		+ mlx.conf.x_start;
	n.y0 = (int)(fd_rotate_y(x, y, m, z) * (double)mlx.conf.between)
		+ mlx.conf.y_start;
	side == -1 ? y++ : x++;
	z = mlx.map.tab[y][x].p;
	n.x1 = (int)(fd_rotate_x(x, y, m, z) * (double)mlx.conf.between)
		+ mlx.conf.x_start;
	n.y1 = (int)(fd_rotate_y(x, y, m, z) * (double)mlx.conf.between)
		+ mlx.conf.y_start;
	return (n);
}
