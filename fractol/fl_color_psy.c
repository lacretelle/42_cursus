/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_color_psy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:57:00 by madufour          #+#    #+#             */
/*   Updated: 2019/03/18 11:21:45 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	fl_colbasic(int i)
{
	int	color;
	int	c[16];

	c[0] = 0x421e0f;
	c[1] = 0x19071a;
	c[2] = 0x09012f;
	c[3] = 0x040449;
	c[4] = 0x000764;
	c[5] = 0x0c2c8a;
	c[6] = 0x1852b1;
	c[7] = 0x397dd1;
	c[8] = 0x86b5e5;
	c[9] = 0xd3ecf8;
	c[10] = 0xf1e9bf;
	c[11] = 0xf8c95f;
	c[12] = 0xffaa00;
	c[13] = 0xcc8000;
	c[14] = 0x995700;
	c[15] = 0x6a3403;
	color = c[i % 16];
	return (color);
}

static int	fl_colelse(int i)
{
	int	color;
	int	c[16];

	c[0] = 0x0008cd;
	c[1] = 0x411bac;
	c[2] = 0x713a98;
	c[3] = 0xa0628b;
	c[4] = 0xffda5f;
	c[5] = 0xf62e9b;
	c[6] = 0xff0300;
	c[7] = 0x3c0000;
	c[8] = 0x003906;
	c[9] = 0x23860f;
	c[10] = 0x77d01c;
	c[11] = 0x6df6fe;
	c[12] = 0xd7ddfd;
	c[13] = 0xffffff;
	c[14] = 0x010bcf;
	c[15] = 0x069e77;
	color = c[i % 16];
	return (color);
}

int			fl_color_psy(int i, t_mlx mlx)
{
	int	color;

	if (mlx.f.palette == 'z')
		color = fl_colbasic(i);
	else
		color = fl_colelse(i);
	return (color);
}
