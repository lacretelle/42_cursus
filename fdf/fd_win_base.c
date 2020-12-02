/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_win_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:35:59 by madufour          #+#    #+#             */
/*   Updated: 2019/03/01 17:54:31 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	fd_win_base(t_mlx mlx)
{
	int		color;
	char	*s;

	color = 0x00000000;
	s = "ZOOM : + OU -";
	mlx_string_put(mlx.mlx, mlx.win, mlx.size_x / 5, 30, color, s);
	s = "DEPLACEMENT : fleches directionnelles  < ^ >";
	mlx_string_put(mlx.mlx, mlx.win, mlx.size_x / 5, 50, color, s);
	s = "HAUTEUR : w OU s";
	mlx_string_put(mlx.mlx, mlx.win, mlx.size_x / 5, 70, color, s);
	s = "PROJECTIONS : 1 = ISOMETRIQUE, 2 = PARALLELE, 3 = ROTATIONS EULER";
	mlx_string_put(mlx.mlx, mlx.win, mlx.size_x / 5, 90, color, s);
	s = "POUR LES ROTATIONS EULER (varier les angles): [ , ] ou \\";
	mlx_string_put(mlx.mlx, mlx.win, mlx.size_x / 5, 110, color, s);
	s = "COULEURS : Z, R, G, B ou *";
	mlx_string_put(mlx.mlx, mlx.win, mlx.size_x / 5, 130, color, s);
	s = "RETOUR CONFIGURATION INITIALE : tab";
	mlx_string_put(mlx.mlx, mlx.win, mlx.size_x / 5, 150, color, s);
	s = "QUITTER : esc";
	mlx_string_put(mlx.mlx, mlx.win, mlx.size_x / 5, 170, color, s);
	return (mlx);
}
