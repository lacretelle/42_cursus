/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:42:35 by madufour          #+#    #+#             */
/*   Updated: 2018/12/12 15:43:12 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_read(int fd, int *i)
{
	char	*line;
	char	*str;
	char	*tmp;
	int		nbL;

	nbL = *i;
	if (!(str = ft_strnew(0)))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		nbL++;
		if ((nbL % 5 != 0 && ft_strlen(line) != 4) ||
			(nbL % 5 == 0 && ft_strcmp(line, "") != 0))
			return (NULL);
		tmp = ft_strjoin(str, line);
		tmp = ft_strjoin(tmp, "\n");
		free(str);
		free(line);
		str = tmp;
	}
	*i = nbL;
	return (str);
}

static char	*check_errors(int fd, int *nb)
{
	int 	nbL;
	char	*s;
	size_t 	i;

	nbL = *nb;
	if ((s = ft_strnew(0)) == 0)
		return (NULL);
	if (!(s = ft_read(fd, &nbL)))
		return (NULL);
	i = ft_strlen(s);
	if (s[i - 1] == '\n' && s[i - 2] == '\n')
		return (NULL);
	ft_putstr(s);
	if ((check_char(s, nbL)) == 0)
   		return (NULL);
	if ((valid_tetris(s)) == 0)
		return (NULL);
	*nb = nbL;
	return (s);
}

int			main(int ac, char **av)
{
	int		fd;
	char	*s;
	int		nbL;

	s = NULL;
	nbL = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!(s = check_errors(fd, nbL)))
		{
			ft_putstr("error\n");
			return (0);
		}
		else
		{
			solve(s, nbL);
			ft_putstr("ok grille valide");
		}
		close(fd);
	}
	//else -- > USAGE
}
