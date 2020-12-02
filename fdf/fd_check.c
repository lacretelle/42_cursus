/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:51:36 by madufour          #+#    #+#             */
/*   Updated: 2019/03/02 16:59:11 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fd_count_x(char *map, int *j)
{
	int	count;
	int	i;

	count = 0;
	i = *j;
	while (map[i] != '\n' && map[i] != '\0')
	{
		if (map[i] != ' ')
		{
			count++;
			while (map[i] != ' ' && map[i] != '\n')
				i++;
		}
		else
			i++;
	}
	*j = i + 1;
	return (count);
}

static int	fd_hexa(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == ',')
			return (1);
		i++;
	}
	return (-1);
}

static int	fd_error_map(int k)
{
	if (k == 1)
		ft_putendl_fd("No data found.", 2);
	else
		ft_putendl_fd("Found wrong line length. Exiting.", 2);
	return (-1);
}

int			fd_check(int y, char *map, int *h)
{
	int	line;
	int	i;
	int count;
	int tmp;

	line = 0;
	i = 0;
	count = 0;
	*h = fd_hexa(map);
	if (map == 0 || map[0] == '\0')
		return (fd_error_map(1));
	while (line < y)
	{
		tmp = fd_count_x(map, &i);
		if (count == 0)
			count = tmp;
		else
		{
			if (count != tmp)
				return (fd_error_map(-1));
		}
		line++;
	}
	return (count);
}
