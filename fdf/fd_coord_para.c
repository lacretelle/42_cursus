/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_coord_para.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:02:21 by madufour          #+#    #+#             */
/*   Updated: 2019/02/26 18:54:07 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	fd_parallele(t_mlx mlx, t_point p)
{
	t_point	n;
	int		i;

	i = mlx.conf.between;
	n.x0 = p.x0 * i + mlx.map.const_x * (mlx.map.tab[p.y0][p.x0].p
			* mlx.map.const_z) * i / 10;
	n.y0 = p.y0 * i + mlx.map.const_x * (mlx.map.tab[p.y0][p.x0].p
			* mlx.map.const_z) * i / 8;
	n.x1 = p.x1 * i + mlx.map.const_x * (mlx.map.tab[p.y1][p.x1].p
			* mlx.map.const_z) * i / 10;
	n.y1 = p.y1 * i + mlx.map.const_x * (mlx.map.tab[p.y1][p.x1].p
			* mlx.map.const_z) * i / 8;
	return (n);
}

static t_point	fd_point_side(t_mlx mlx, int x, int y)
{
	t_point	side;

	side.x0 = x;
	side.y0 = y;
	side.x1 = x + 1;
	side.y1 = y;
	side = fd_parallele(mlx, side);
	return (side);
}

static t_point	fd_point_down(t_mlx mlx, int x, int y)
{
	t_point	down;

	down.x0 = x;
	down.y0 = y;
	down.x1 = x;
	down.y1 = y + 1;
	down = fd_parallele(mlx, down);
	return (down);
}

static t_point	fd_add_start(t_mlx mlx, t_point point)
{
	point.x0 = point.x0 + mlx.conf.x_start;
	point.x1 = point.x1 + mlx.conf.x_start;
	point.y0 = point.y0 + mlx.conf.y_start;
	point.y1 = point.y1 + mlx.conf.y_start;
	return (point);
}

t_point			fd_coord_para(t_mlx mlx, int x, int y, int way)
{
	t_point	p;

	if (way < 0)
		p = fd_point_down(mlx, x, y);
	else
		p = fd_point_side(mlx, x, y);
	p = fd_add_start(mlx, p);
	return (p);
}
