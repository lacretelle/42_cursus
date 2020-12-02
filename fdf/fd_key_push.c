/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_key_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:26:31 by madufour          #+#    #+#             */
/*   Updated: 2019/03/01 17:26:35 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fd_deplace(t_mlx *mlx, int k)
{
	if (k == 126)
		mlx->conf.y_start -= 10;
	if (k == 124)
		mlx->conf.x_start += 10;
	if (k == 125)
		mlx->conf.y_start += 10;
	if (k == 123)
		mlx->conf.x_start -= 10;
}

static void	fd_manage_z_proj(t_mlx *mlx, int k)
{
	if (k == 13 || k == 1)
	{
		if (k == 1 && mlx->map.const_z >= -10)
			mlx->map.const_z -= 1;
		else if (k == 13 && mlx->map.const_z <= 10)
			mlx->map.const_z += 1;
	}
	if (k == 18)
		mlx->conf.project = 1;
	if (k == 19)
		mlx->conf.project = 2;
	if (k == 20)
		mlx->conf.project = 3;
}

static void	fd_palette_color(t_mlx *mlx, int k)
{
	if (k == 15)
		mlx->conf.color = 0xff0000;
	if (k == 5)
		mlx->conf.color = 0x00ff00;
	if (k == 11)
		mlx->conf.color = 0xff;
	if (k == 67)
		mlx->conf.color = 0xffffff;
	if (k == 6)
		mlx->conf.color = 0x0048d1cc;
}

static void	fd_manage_img(int k, t_mlx *mlx)
{
	t_map map;

	map = mlx->map;
	if (k == 24 || k == 27)
	{
		if (k == 24 && mlx->conf.between < (mlx->size_x / 5))
			mlx->conf.between += 5;
		else
		{
			if (mlx->conf.between > 5)
				mlx->conf.between -= 5;
		}
	}
	if (k >= 123 && k <= 126)
		fd_deplace(mlx, k);
	if (k == 13 || k == 1 || (k >= 18 && k <= 20))
		fd_manage_z_proj(mlx, k);
	if (k == 30 || k == 33 || k == 42)
		fd_manage_euler(mlx, k);
	if (k == 15 || k == 5 || k == 11 || k == 67 || k == 6)
		fd_palette_color(mlx, k);
	if (k == 48)
		*mlx = fd_init_conf(*mlx);
	fd_modif_img(*mlx);
}

int			fd_key_push(int key, void *param)
{
	t_mlx		*mlx;
	t_tabmap	**tab;

	mlx = (t_mlx*)param;
	if (key == 53)
	{
		tab = mlx->map.tab;
		fd_delete((void***)&tab);
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	else
		fd_manage_img(key, mlx);
	return (0);
}
