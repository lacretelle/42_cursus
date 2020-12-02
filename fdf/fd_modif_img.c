/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_modif_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:50:10 by madufour          #+#    #+#             */
/*   Updated: 2019/02/28 15:58:38 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mlx	fd_draw(t_mlx mlx, int x, int y, int color)
{
	t_point point;

	if (!(y == mlx.map.y - 1))
	{
		if (mlx.conf.project == 1)
			point = fd_coord_iso(mlx, x, y, -1);
		else if (mlx.conf.project == 2)
			point = fd_coord_para(mlx, x, y, -1);
		else
			point = fd_coord_euler(mlx, x, y, -1);
		mlx = fd_draw_line(mlx, point, color);
	}
	if (!(x == mlx.map.x - 1))
	{
		if (mlx.conf.project == 1)
			point = fd_coord_iso(mlx, x, y, 1);
		else if (mlx.conf.project == 2)
			point = fd_coord_para(mlx, x, y, 1);
		else
			point = fd_coord_euler(mlx, x, y, 1);
		mlx = fd_draw_line(mlx, point, color);
	}
	return (mlx);
}

static t_mlx	fd_fill_img(t_mlx mlx)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < mlx.map.y)
	{
		x = 0;
		while (x < mlx.map.x)
		{
			color = fd_color(mlx, x, y);
			mlx = fd_draw(mlx, x, y, color);
			x++;
		}
		y++;
	}
	return (mlx);
}

static t_mlx	fd_clear_img(t_mlx mlx)
{
	int	size;
	int	i;

	size = mlx.size_x * mlx.size_y;
	i = 0;
	while (i < size && size > 0)
	{
		mlx.data[i] = 0;
		i++;
	}
	return (mlx);
}

t_mlx			fd_modif_img(t_mlx mlx)
{
	int	i;
	int	j;

	i = 0;
	mlx = fd_clear_img(mlx);
	while (i < 200)
	{
		j = 0;
		while (j < mlx.size_x)
		{
			mlx.data[j + i * mlx.size_line / 4] = mlx.conf.color;
			j++;
		}
		i++;
	}
	mlx = fd_fill_img(mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx = fd_win_base(mlx);
	return (mlx);
}
