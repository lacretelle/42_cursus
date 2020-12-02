/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_burningship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:07:40 by madufour          #+#    #+#             */
/*   Updated: 2019/03/18 15:04:41 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static int		fl_burn(t_mlx *mlx, int x, int y, t_conf c)
{
	t_compl	t;
	int		i;
	double	tmp;

	t.c_r = (double)x / c.zoomx + mlx->f.x1 - (mlx->f.offx
			* (mlx->f.x2 - mlx->f.x1) / mlx->size_x);
	t.c_i = (double)y / c.zoomy + mlx->f.y1 - (mlx->f.offy
			* (mlx->f.y2 - mlx->f.y1) / mlx->size_y);
	t.z_r = 0;
	t.z_i = 0;
	i = 0;
	while (t.z_r * t.z_r + t.z_i * t.z_i < 4 && i < mlx->f.it_max)
	{
		tmp = t.z_r;
		t.z_r = t.z_r * t.z_r - t.z_i * t.z_i + t.c_r;
		t.z_i = 2 * fabs(tmp * t.z_i) + t.c_i;
		i++;
	}
	if (i != mlx->f.it_max)
		return (i);
	return (-1);
}

static void		*fl_burn_thread(void *param)
{
	t_data	*data;
	int		x;
	int		i;

	data = (t_data*)param;
	x = 0;
	while (x < data->mlx->size_x)
	{
		i = fl_burn(data->mlx, x, data->y, data->c);
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
		pthread_create(&(th.thread[y]), NULL, fl_burn_thread, &(th.data[y]));
		y++;
	}
	y = 0;
	while (y < mlx->size_y)
	{
		pthread_join(th.thread[y], NULL);
		y++;
	}
}

t_mlx			fl_burningship(t_mlx *mlx)
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
