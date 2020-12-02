/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 12:03:14 by madufour          #+#    #+#             */
/*   Updated: 2019/02/22 15:25:50 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mlx	img_put_pxl(t_mlx mlx, int x, int y, int color)
{
	if (x < mlx.size_x && y < mlx.size_y && x >= 0 && y >= 0)
		mlx.data[x + y * mlx.size_line / 4] = color;
	return (mlx);
}

static t_bre	fd_init_bre(t_point point)
{
	t_bre	b;

	b.dx = point.x1 - point.x0;
	b.dy = point.y1 - point.y0;
	b.oct_x = (b.dx > 0) ? 1 : -1;
	b.oct_y = (b.dy > 0) ? 1 : -1;
	if (b.dx < 0)
		b.dx *= -1;
	if (b.dy < 0)
		b.dy *= -1;
	return (b);
}

static t_mlx	fd_bre_x(t_mlx mlx, t_point point, t_bre b, int color)
{
	int	i;
	int	dp;

	i = 1;
	dp = b.dx / 2;
	while (i <= b.dx)
	{
		point.x0 += b.oct_x;
		dp += b.dy;
		if (dp >= b.dx)
		{
			dp -= b.dx;
			point.y0 += b.oct_y;
		}
		mlx = img_put_pxl(mlx, point.x0, point.y0, color);
		i++;
	}
	return (mlx);
}

static t_mlx	fd_bre_y(t_mlx mlx, t_point point, t_bre b, int color)
{
	int	i;
	int	dp;

	i = 1;
	dp = b.dy / 2;
	while (i <= b.dy)
	{
		point.y0 += b.oct_y;
		dp += b.dx;
		if (dp >= b.dy)
		{
			dp -= b.dy;
			point.x0 += b.oct_x;
		}
		mlx = img_put_pxl(mlx, point.x0, point.y0, color);
		i++;
	}
	return (mlx);
}

t_mlx			fd_draw_line(t_mlx mlx, t_point point, int color)
{
	t_bre	b;

	b = fd_init_bre(point);
	if (b.dx > b.dy)
		mlx = fd_bre_x(mlx, point, b, color);
	else
		mlx = fd_bre_y(mlx, point, b, color);
	return (mlx);
}
