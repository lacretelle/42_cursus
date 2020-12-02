/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:12:46 by madufour          #+#    #+#             */
/*   Updated: 2019/03/18 15:12:22 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fl_off_pal(int k, t_mlx *mlx)
{
	if (k == 123)
		mlx->f.offx += (10 / mlx->f.zoom);
	if (k == 124)
		mlx->f.offx -= (10 / mlx->f.zoom);
	if (k == 125)
		mlx->f.offy -= (10 / mlx->f.zoom);
	if (k == 126)
		mlx->f.offy += (10 / mlx->f.zoom);
	if (k == 0)
		mlx->f.palette = 'e';
	if (k == 6)
		mlx->f.palette = 'z';
	if (k == 15)
		mlx->f.palette = 'r';
	if (k == 5)
		mlx->f.palette = 'g';
	if (k == 11)
		mlx->f.palette = 'b';
}

static void	fl_zoom(int k, t_mlx *mlx)
{
	double	zoom;
	double	x;
	double	y;

	x = mlx->f.d.x;
	y = mlx->f.d.y;
	if (k == 27 && mlx->f.zoom >= 0.1)
	{
		zoom = mlx->f.zoom / 1.1;
		if (mlx->f.it_max >= 40)
			mlx->f.it_max -= 5;
		mlx->f.offx += (x - x * zoom / mlx->f.zoom) / zoom;
		mlx->f.offy += (y - y * zoom / mlx->f.zoom) / zoom;
		mlx->f.zoom = zoom;
	}
	else
	{
		zoom = mlx->f.zoom * 1.1;
		if (mlx->f.it_max <= 1000)
			mlx->f.it_max += 5;
		mlx->f.offx += (x - x * zoom / mlx->f.zoom) / zoom;
		mlx->f.offy += (y - y * zoom / mlx->f.zoom) / zoom;
		mlx->f.zoom = zoom;
	}
}

static void	fl_manage_fract(int k, t_mlx *mlx)
{
	if ((k >= 123 && k <= 126) || k == 5 || k == 6 || k == 11
			|| k == 15 || k == 0)
		fl_off_pal(k, mlx);
	if (k == 49)
	{
		if (mlx->f.m_move == 1)
			mlx->f.m_move = 0;
		else
			mlx->f.m_move = 1;
	}
	if (k == 24 || k == 27)
		fl_zoom(k, mlx);
	if (k == 48)
		mlx->f = fl_init(mlx->f.name);
	if (k == 46)
	{
		if (mlx->use == 1)
			mlx->use = 0;
		else
			mlx->use = 1;
	}
}

int			fl_key(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	if (key == 53)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	else
	{
		fl_manage_fract(key, mlx);
		if (mlx->f.name == 'm')
			fl_mandelbrot(mlx);
		else if (mlx->f.name == 'j')
			fl_julia(mlx);
		else
			fl_burningship(mlx);
	}
	return (1);
}
