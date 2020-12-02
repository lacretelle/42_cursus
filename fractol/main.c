/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 15:08:39 by madufour          #+#    #+#             */
/*   Updated: 2019/03/18 15:31:44 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_mlx	fl_init_window(void)
{
	t_mlx	mlx;

	mlx.size_x = FRACT_W;
	mlx.size_y = FRACT_H;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.size_x, mlx.size_y, "mlx 42");
	mlx.img = mlx_new_image(mlx.mlx, mlx.size_x, mlx.size_y);
	mlx.data = (int*)mlx_get_data_addr(mlx.img, \
			&(mlx.bpp), &(mlx.size_line), &(mlx.endian));
	mlx.use = 0;
	return (mlx);
}

static void		fl_choice(char name)
{
	t_mlx	mlx;

	mlx = fl_init_window();
	if (!(mlx.mlx))
	{
		ft_putendl_fd("Error initializing window. Exit.", 2);
		return ;
	}
	mlx.f = fl_init(name);
	if (name == 'm')
		mlx = fl_mandelbrot(&mlx);
	else if (name == 'j')
		mlx = fl_julia(&mlx);
	else
		mlx = fl_burningship(&mlx);
	mlx_hook(mlx.win, 2, (1L >> 0), fl_key, &mlx);
	mlx_hook(mlx.win, 4, (1L >> 0), fl_mouse, &mlx);
	mlx_hook(mlx.win, 6, (1L >> 0), fl_mouse_move, &mlx);
	mlx_hook(mlx.win, 5, (1L >> 0), fl_mouse_release, &mlx);
	mlx_hook(mlx.win, 17, (1L >> 0), fl_close, &mlx);
	mlx_loop(mlx.mlx);
}

static int		fl_error(int i)
{
	if (i == 1)
	{
		ft_putendl_fd("Usage: ./fractol [ param ]", 2);
		ft_putendl_fd("param: \"mandelbrot\" \"julia\" \"burningship\"", 2);
	}
	return (1);
}

int				main(int ac, char **av)
{
	char	name;

	name = 0;
	if (ac == 2)
	{
		if ((ft_strcmp(av[ac - 1], "mandelbrot")) == 0)
			name = 'm';
		else if ((ft_strcmp(av[ac - 1], "julia")) == 0)
			name = 'j';
		else if ((ft_strcmp(av[ac - 1], "burningship")) == 0)
			name = 'b';
		else
			return (fl_error(1));
		fl_choice(name);
	}
	else
		return (fl_error(1));
	return (0);
}
