/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:14:04 by madufour          #+#    #+#             */
/*   Updated: 2019/03/18 14:32:51 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			fl_mouse_release(int k, int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	(void)x;
	(void)y;
	if (k == 1)
	{
		mlx->f.d.on = 0;
		mlx->f.d.x = 0;
		mlx->f.d.y = 0;
	}
	return (1);
}

static void	fl_drag(int x, int y, t_mlx *mlx)
{
	mlx->f.offx += (x - mlx->f.d.x) / mlx->f.zoom;
	mlx->f.offy += (y - mlx->f.d.y) / mlx->f.zoom;
	mlx->f.d.x = x;
	mlx->f.d.y = y;
	if (mlx->f.name == 'm')
		fl_mandelbrot(mlx);
	else if (mlx->f.name == 'j')
		fl_julia(mlx);
	else
		fl_burningship(mlx);
}

int			fl_mouse_move(int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (mlx->f.d.on == 0 && x > 0 && y > 0 && x < mlx->size_x
			&& y < mlx->size_y)
	{
		mlx->f.d.x = x;
		mlx->f.d.y = y;
	}
	if (mlx->f.name == 'j' && x > 0 && x < mlx->size_x && y < mlx->size_y
			&& y > 0 && mlx->f.m_move == 1)
	{
		mlx->f.j_cr = x / (mlx->size_x / (0.3 + 1.5)) - 1.5;
		mlx->f.j_ci = y / (mlx->size_y / (1 - 0.001)) - 0.001;
		fl_julia(mlx);
	}
	if (mlx->f.d.on == 1 && x > 0 && y > 0 && x < mlx->size_x
			&& y < mlx->size_y)
		fl_drag(x, y, mlx);
	return (1);
}

static void	fl_zoom(t_mlx *mlx, int x, int y, int k)
{
	double	zoom;

	if (k == 4 && mlx->f.zoom >= 0.1)
	{
		zoom = mlx->f.zoom / 1.1;
		if (mlx->f.it_max >= 40)
			mlx->f.it_max -= 5;
		mlx->f.offx += ((double)x - (double)x * zoom / mlx->f.zoom) / zoom;
		mlx->f.offy += ((double)y - (double)y * zoom / mlx->f.zoom) / zoom;
		mlx->f.zoom = zoom;
	}
	else if (k == 5)
	{
		zoom = mlx->f.zoom * 1.1;
		if (mlx->f.it_max <= 1000)
			mlx->f.it_max += 5;
		mlx->f.offx += ((double)x - (double)x * zoom / mlx->f.zoom) / zoom;
		mlx->f.offy += ((double)y - (double)y * zoom / mlx->f.zoom) / zoom;
		mlx->f.zoom = zoom;
	}
}

int			fl_mouse(int k, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (k == 4 || k == 5)
		fl_zoom(mlx, x, y, k);
	else if (k == 1 && x > 0 && y > 0 && x < mlx->size_x && y < mlx->size_y)
	{
		mlx->f.d.on = 1;
		mlx->f.d.x = x;
		mlx->f.d.y = y;
	}
	if (mlx->f.name == 'm')
		fl_mandelbrot(mlx);
	else if (mlx->f.name == 'j')
		fl_julia(mlx);
	else
		fl_burningship(mlx);
	return (1);
}
