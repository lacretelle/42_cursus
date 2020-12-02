/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:17:07 by madufour          #+#    #+#             */
/*   Updated: 2019/03/18 10:22:57 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		fl_pix_julia(t_mlx *mlx, int x, int y, t_conf c)
{
	double	tp_x;
	double	z_r;
	double	z_i;
	int		i;

	z_r = (double)x / c.zoomx + mlx->f.x1 - (mlx->f.offx
			* (mlx->f.x2 - mlx->f.x1) / mlx->size_x);
	z_i = (double)y / c.zoomy + mlx->f.y1 - (mlx->f.offy
			* (mlx->f.y2 - mlx->f.y1) / mlx->size_y);
	i = 0;
	while (z_r * z_r + z_i * z_i < 4
			&& i < mlx->f.it_max)
	{
		tp_x = z_r;
		z_r = tp_x * tp_x - z_i * z_i + mlx->f.j_cr;
		z_i = 2 * tp_x * z_i + mlx->f.j_ci;
		i++;
	}
	if (i != mlx->f.it_max)
		return (i);
	return (-1);
}

static void		*fl_julia_thread(void *param)
{
	t_data	*data;
	int		x;
	int		i;

	data = (t_data*)param;
	x = 0;
	while (x < data->mlx->size_x)
	{
		i = fl_pix_julia(data->mlx, x, data->y, data->c);
		fl_draw(data->mlx, x, data->y, i);
		x++;
	}
	return (0);
}

static t_data	fl_newdata(t_mlx *mlx, int y, t_conf c)
{
	t_data	d;

	d.mlx = mlx;
	d.c = c;
	d.y = y;
	return (d);
}

static void		fl_fill_img(t_mlx *mlx)
{
	int		y;
	t_mult	th;
	t_conf	c;

	c.zoomx = mlx->size_x / (mlx->f.x2 - mlx->f.x1) * mlx->f.zoom;
	c.zoomy = mlx->size_y / (mlx->f.y2 - mlx->f.y1) * mlx->f.zoom;
	y = 0;
	while (y < mlx->size_y)
	{
		th.data[y] = fl_newdata(mlx, y, c);
		pthread_create(&(th.thread[y]), NULL, fl_julia_thread, &(th.data[y]));
		y++;
	}
	y = 0;
	while (y < mlx->size_y)
	{
		pthread_join(th.thread[y], NULL);
		y++;
	}
}

t_mlx			fl_julia(t_mlx *mlx)
{
	int	i;
	int	j;

	fl_clear_img(mlx);
	fl_fill_img(mlx);
	i = 380;
	if (mlx->use == 1)
	{
		while (i < 600)
		{
			j = 80;
			while (j < 600)
			{
				mlx->data[j + i * mlx->size_line / 4] = 0xf1e9bf;
				j++;
			}
			i++;
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	if (mlx->use == 1)
		*mlx = fl_user(*mlx);
	return (*mlx);
}
