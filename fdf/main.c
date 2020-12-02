/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 15:08:39 by madufour          #+#    #+#             */
/*   Updated: 2019/03/02 16:58:48 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mlx	fd_initial(t_map map)
{
	t_mlx	mlx;

	mlx.size_x = 2560;
	mlx.size_y = 1440;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.size_x, mlx.size_y, "mlx 42");
	mlx.img = mlx_new_image(mlx.mlx, mlx.size_x, mlx.size_y);
	mlx.data = (int*)mlx_get_data_addr(mlx.img, \
			&(mlx.bpp), &(mlx.size_line), &(mlx.endian));
	mlx.map = map;
	mlx = fd_init_conf(mlx);
	return (mlx);
}

static void		fd_window(t_map map)
{
	t_mlx	mlx;

	mlx = fd_initial(map);
	mlx = fd_modif_img(mlx);
	mlx_hook(mlx.win, 2, (1L >> 0), fd_key_push, &mlx);
	mlx_loop(mlx.mlx);
}

int				main(int ac, char **av)
{
	t_map	map;
	int		fd;

	if (ac != 2)
		ft_putendl_fd("Usage : ./fdf <filename>", 2);
	else
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_putendl_fd("No data found.", 2);
			return (1);
		}
		map.tab = fd_read(fd, &map.x, &map.y);
		close(fd);
		if ((map.tab))
			fd_window(map);
	}
	return (0);
}
