/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:17:47 by madufour          #+#    #+#             */
/*   Updated: 2019/03/02 17:07:25 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define W 2560
# define H 1440

typedef struct	s_tabmap
{
	int	color;
	int	p;
}				t_tabmap;

typedef struct	s_map
{
	t_tabmap	**tab;
	int			x;
	int			y;
	int			max;
	int			min;
	int			const_x;
	int			const_y;
	int			const_z;
}				t_map;

typedef struct	s_euler
{
	int	teta;
	int	nu;
	int	alpha;
}				t_euler;

typedef struct	s_conf
{
	t_euler	angle;
	int		x_start;
	int		y_start;
	int		between;
	int		color;
	int		project;
}				t_conf;

typedef struct	s_mlx
{
	t_map	map;
	t_conf	conf;
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	int		*data;
	int		size_x;
	int		size_y;
}				t_mlx;

typedef struct	s_point
{
	int x0;
	int y0;
	int	x1;
	int	y1;
}				t_point;

typedef struct	s_ang
{
	double	a;
	double	b;
	double	c;
}				t_ang;

typedef struct	s_bre
{
	int	dx;
	int	dy;
	int	oct_x;
	int	oct_y;
}				t_bre;

t_tabmap		**fd_read(int fd, int *x, int *y);
t_mlx			fd_init_conf(t_mlx mlx);
t_mlx			fd_modif_img(t_mlx mlx);
void			fd_delete(void ***p);
t_mlx			fd_draw_line(t_mlx mlx, t_point point, int color);
t_point			fd_coord_iso(t_mlx mlx, int x, int y, int way);
t_point			fd_coord_para(t_mlx mlx, int x, int y, int way);
t_point			fd_coord_euler(t_mlx mlx, int x, int y, int side);
void			fd_manage_euler(t_mlx *mlx, int k);
int				fd_key_push(int key, void *param);
int				fd_check(int y, char *map, int *h);
int				fd_color(t_mlx mlx, int x, int y);
int				fd_deg_color(char c, int m);
int				fd_atoi_hexa(char *s);
t_tabmap		**fd_manage_hexa(char **lines, int x, t_tabmap **tab);
t_tabmap		**fd_map_classic(char **lines, int x, int y, t_tabmap **tab);
t_mlx			fd_win_base(t_mlx mlx);

#endif
