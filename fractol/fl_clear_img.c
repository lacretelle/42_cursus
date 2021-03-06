/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_clear_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:05:40 by madufour          #+#    #+#             */
/*   Updated: 2019/03/14 16:06:31 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fl_clear_img(t_mlx *mlx)
{
	int	size;
	int	i;

	size = mlx->size_x * mlx->size_y;
	i = 0;
	while (i < size && size > 0)
	{
		mlx->data[i] = 0;
		i++;
	}
}
