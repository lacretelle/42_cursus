/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_user.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 23:08:43 by madufour          #+#    #+#             */
/*   Updated: 2019/03/18 11:37:55 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	fl_user(t_mlx mlx)
{
	int		color;
	char	*s;

	color = 0xff5555;
	s = "ZOOM : ( + OU - ) AND  Mouse wheel";
	mlx_string_put(mlx.mlx, mlx.win, 100, 400, color, s);
	s = "DEPLACEMENT : fleches directionnelles  < ^ >";
	mlx_string_put(mlx.mlx, mlx.win, 100, 420, color, s);
	s = "DRAG AND DROP: click right mouse";
	mlx_string_put(mlx.mlx, mlx.win, 100, 440, color, s);
	s = "COULEURS : R, G, B, A AND Z";
	mlx_string_put(mlx.mlx, mlx.win, 100, 460, color, s);
	s = "RETOUR CONFIGURATION INITIALE : tab";
	mlx_string_put(mlx.mlx, mlx.win, 100, 480, color, s);
	s = "STOP/START CHANGING PARAMETER JULIA :  space";
	mlx_string_put(mlx.mlx, mlx.win, 100, 500, color, s);
	s = "QUITTER : esc";
	mlx_string_put(mlx.mlx, mlx.win, 100, 520, color, s);
	return (mlx);
}
