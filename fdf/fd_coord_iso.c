/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_coord_iso.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:19:43 by madufour          #+#    #+#             */
/*   Updated: 2019/02/26 19:14:03 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	fd_iso(t_mlx mlx, t_point p)
{
	t_point	n;

	n.x0 = p.x0 * mlx.map.const_x - p.y0 * mlx.map.const_y;
	n.y0 = p.x0 * mlx.map.const_x + p.y0 * mlx.map.const_y -
		(mlx.map.tab[p.y0][p.x0].p * mlx.map.const_z);
	n.x1 = p.x1 * mlx.map.const_x - p.y1 * mlx.map.const_y;
	n.y1 = p.x1 * mlx.map.const_x + p.y1 * mlx.map.const_y -
		(mlx.map.tab[p.y1][p.x1].p * mlx.map.const_z);
	return (n);
}

static t_point	fd_point_side(t_mlx mlx, int x, int y)
{
	t_point	side;

	side.x0 = x;
	side.y0 = y;
	side.x1 = x + 1;
	side.y1 = y;
	side = fd_iso(mlx, side);
	return (side);
}

static t_point	fd_point_down(t_mlx mlx, int x, int y)
{
	t_point	down;

	down.x0 = x;
	down.y0 = y;
	down.x1 = x;
	down.y1 = y + 1;
	down = fd_iso(mlx, down);
	return (down);
}

static t_point	fd_add_start(t_mlx mlx, t_point point)
{
	point.x0 = point.x0 * mlx.conf.between + mlx.conf.x_start;
	point.x1 = point.x1 * mlx.conf.between + mlx.conf.x_start;
	point.y0 = point.y0 * mlx.conf.between / 2 + mlx.conf.y_start;
	point.y1 = point.y1 * mlx.conf.between / 2 + mlx.conf.y_start;
	return (point);
}

t_point			fd_coord_iso(t_mlx mlx, int x, int y, int way)
{
	t_point	p;

	if (way < 0)
		p = fd_point_down(mlx, x, y);
	else
		p = fd_point_side(mlx, x, y);
	p = fd_add_start(mlx, p);
	return (p);
}
