/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:30:16 by madufour          #+#    #+#             */
/*   Updated: 2019/03/18 11:13:19 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	fl_colred(int i)
{
	int	c[10];
	int	color;

	c[0] = 0x7f0a00;
	c[1] = 0x7f2e28;
	c[2] = 0xcc1000;
	c[3] = 0xff1400;
	c[4] = 0xff3d2c;
	c[5] = 0xff4800;
	c[6] = 0xff6e00;
	c[7] = 0xff9000;
	c[8] = 0xffae00;
	c[9] = 0xffd65e;
	color = c[i % 10];
	return (color);
}

static int	fl_colblue(int i)
{
	int	c[10];
	int	color;

	c[0] = 0x07467f;
	c[1] = 0x0b70cc;
	c[2] = 0x2e597f;
	c[3] = 0x0d8cff;
	c[4] = 0x39a1ff;
	c[5] = 0x8217fe;
	c[6] = 0xbc17fe;
	c[7] = 0xfd17fe;
	c[8] = 0xeaa4fe;
	c[9] = 0xc2fff7;
	color = c[i % 10];
	return (color);
}

static int	fl_colgreen(int i)
{
	int	c[10];
	int	color;

	c[0] = 0x077f2a;
	c[1] = 0x0bcc44;
	c[2] = 0x3d7f51;
	c[3] = 0x0dff4d;
	c[4] = 0x55ff81;
	c[5] = 0x00b781;
	c[6] = 0x00b7b2;
	c[7] = 0x00cea9;
	c[8] = 0x5efea7;
	c[9] = 0xadfebc;
	color = c[i % 10];
	return (color);
}

int			fl_color(int i, t_mlx mlx)
{
	int	color;

	if (i < 0)
		return (0);
	if (mlx.f.palette == 'r')
		color = fl_colred(i);
	else if (mlx.f.palette == 'b')
		color = fl_colblue(i);
	else if (mlx.f.palette == 'g')
		color = fl_colgreen(i);
	else
		color = fl_color_psy(i, mlx);
	return (color);
}
