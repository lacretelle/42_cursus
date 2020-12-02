/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:16:36 by madufour          #+#    #+#             */
/*   Updated: 2019/03/18 15:27:33 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fract	fl_init_julia(t_drag d, char c)
{
	t_fract	m;

	m.x1 = -1;
	m.x2 = 1;
	m.y1 = -1.2;
	m.y2 = 1.2;
	m.zoom = 1;
	m.offx = 0;
	m.offy = 0;
	m.it_max = 50;
	m.j_cr = 0.285;
	m.j_ci = 0.01;
	m.name = c;
	m.palette = 'z';
	m.m_move = 1;
	m.d = d;
	return (m);
}

static t_fract	fl_init_mandel(t_drag d, char c)
{
	t_fract	m;

	m.x1 = -2.1;
	m.x2 = 0.6;
	m.y1 = -1.2;
	m.y2 = 1.2;
	m.zoom = 1;
	m.offx = 0;
	m.offy = 0;
	m.it_max = 50;
	m.j_cr = 0;
	m.j_ci = 0;
	m.name = c;
	m.palette = 'z';
	m.m_move = 1;
	m.d = d;
	return (m);
}

static t_fract	fl_init_burn(t_drag d, char c)
{
	t_fract	m;

	m.x1 = -2.0;
	m.x2 = 1.5;
	m.y1 = -1.5;
	m.y2 = 1.5;
	m.zoom = 1;
	m.offx = 0;
	m.offy = 0;
	m.it_max = 50;
	m.j_cr = 0;
	m.j_ci = 0;
	m.name = c;
	m.palette = 'z';
	m.m_move = 1;
	m.d = d;
	return (m);
}

t_fract			fl_init(char c)
{
	t_fract	m;
	t_drag	d;

	d.x = 0;
	d.y = 0;
	d.on = 0;
	if (c == 'j')
		m = fl_init_julia(d, c);
	else if (c == 'b')
		m = fl_init_burn(d, c);
	else
		m = fl_init_mandel(d, c);
	return (m);
}
