/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_conf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:06:11 by madufour          #+#    #+#             */
/*   Updated: 2019/03/01 17:26:39 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fd_z_min(t_mlx mlx)
{
	int		i;
	int		j;
	long	min;

	j = 0;
	min = 2147483647;
	while (j < mlx.map.y)
	{
		i = 0;
		while (i < mlx.map.x)
		{
			if (mlx.map.tab[j][i].p < min)
				min = mlx.map.tab[j][i].p;
			i++;
		}
		j++;
	}
	return ((int)min);
}

static int		fd_z_max(t_mlx mlx)
{
	int		i;
	int		j;
	long	max;

	j = 0;
	max = -2147483648;
	while (j < mlx.map.y)
	{
		i = 0;
		while (i < mlx.map.x)
		{
			if (mlx.map.tab[j][i].p > max)
				max = mlx.map.tab[j][i].p;
			i++;
		}
		j++;
	}
	return ((int)max);
}

t_mlx			fd_init_conf(t_mlx mlx)
{
	t_conf	conf;
	t_euler	ag;

	mlx.map.const_x = 2;
	mlx.map.const_y = 2;
	mlx.map.const_z = 1;
	mlx.map.max = fd_z_max(mlx);
	mlx.map.min = fd_z_min(mlx);
	conf.x_start = mlx.size_x / 2;
	conf.y_start = 400;
	conf.between = conf.y_start / mlx.map.y;
	if (conf.between < 1)
		conf.between = 1;
	conf.color = 0x0048D1CC;
	conf.project = 1;
	ag.teta = 0;
	ag.nu = 0;
	ag.alpha = 0;
	conf.angle = ag;
	mlx.conf = conf;
	return (mlx);
}
