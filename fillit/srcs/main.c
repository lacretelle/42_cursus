/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:42:35 by madufour          #+#    #+#             */
/*   Updated: 2019/01/10 18:50:21 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char	*return_error(char *str)
{
	ft_strdel(&str);
	return (NULL);
}

static char	*ft_read(int fd, int *i)
{
	char	*line;
	char	*str;
	char	*tmp;
	int		nbl;

	nbl = *i;
	if (!(str = ft_strnew(0)))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		nbl++;
		if ((nbl % 5 != 0 && ft_strlen(line) != 4) ||
			(nbl % 5 == 0 && ft_strcmp(line, "") != 0))
		{
			ft_strdel(&line);
			return (return_error(str));
		}
		tmp = ft_strjoin_free(str, line);
		ft_strdel(&line);
		str = ft_strjoin_free(tmp, "\n");
	}
	if ((nbl + 1) % 5 != 0)
		return (return_error(str));
	*i = nbl;
	return (str);
}

static char	*check_errors(int fd, int *nb)
{
	int		nbl;
	char	*s;
	size_t	i;

	nbl = *nb;
	if (!(s = ft_read(fd, &nbl)))
		return (return_error(s));
	if (ft_strcmp(s, "") == 0)
		return (return_error(s));
	i = ft_strlen(s);
	if (s[i - 1] == '\n' && s[i - 2] == '\n')
		return (return_error(s));
	if (check_char(s, nbl) == 0)
		return (return_error(s));
	if (valid_tetris(s) == 0)
		return (return_error(s));
	if (split_tetri(s) == 0)
		return (return_error(s));
	*nb = nbl;
	return (s);
}

int			main(int ac, char **av)
{
	int		fd;
	char	*s;
	int		nbl;

	nbl = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!(s = check_errors(fd, &nbl)))
		{
			ft_strdel(&s);
			ft_putstr("error\n");
			return (1);
		}
		else if ((solve(s, nbl)) == 0)
		{
			ft_strdel(&s);
			return (1);
		}
		close(fd);
	}
	else
		ft_putendl("usage : ./fillit target_file");
	ft_strdel(&s);
	return (0);
}
