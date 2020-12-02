/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_deg_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:56:36 by madufour          #+#    #+#             */
/*   Updated: 2019/02/25 13:26:27 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fd_fill_r(int m)
{
	int	color;

	if (m == 1)
		color = 0xff0023;
	else if (m == 2)
		color = 0xff415b;
	else if (m == 3)
		color = 0xff5f74;
	else if (m == 4)
		color = 0xff8b9b;
	else
		color = 0xffbcc5;
	return (color);
}

static int	fd_fill_g(int m)
{
	int	color;

	if (m == 1)
		color = 0x009404;
	else if (m == 2)
		color = 0x01b606;
	else if (m == 3)
		color = 0x05e70c;
	else if (m == 4)
		color = 0x52ff58;
	else
		color = 0x94ff97;
	return (color);
}

static int	fd_fill_b(int m)
{
	int	color;

	if (m == 1)
		color = 0x0094fa;
	else if (m == 2)
		color = 0x35acfe;
	else if (m == 3)
		color = 0x23d3fe;
	else if (m == 4)
		color = 0x91e9ff;
	else
		color = 0xb2f7ff;
	return (color);
}

static int	fd_fill_a(int m)
{
	int	color;

	if (m == 1)
		color = 0x6e03ff;
	else if (m == 2)
		color = 0x03ffd;
	else if (m == 3)
		color = 0x90ff03;
	else if (m == 4)
		color = 0xffca03;
	else
		color = 0xff5303;
	return (color);
}

int			fd_deg_color(char c, int m)
{
	int	color;

	if (c == 'r')
		color = fd_fill_r(m);
	else if (c == 'g')
		color = fd_fill_g(m);
	else if (c == 'b')
		color = fd_fill_b(m);
	else
		color = fd_fill_a(m);
	return (color);
}
