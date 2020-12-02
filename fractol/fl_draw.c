/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:40:38 by madufour          #+#    #+#             */
/*   Updated: 2019/03/18 15:26:58 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fl_draw(t_mlx *mlx, int x, int y, int i)
{
	int	color;

	color = fl_color(i, *mlx);
	if (x < mlx->size_x && y < mlx->size_y && x >= 0 && y >= 0)
		mlx->data[x + y * mlx->size_line / 4] = color;
}
