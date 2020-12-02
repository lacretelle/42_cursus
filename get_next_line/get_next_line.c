/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:13:57 by madufour          #+#    #+#             */
/*   Updated: 2018/11/30 18:36:56 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(const int fd, char **tmp)
{
	int ret;
	char *tp;
	char buf[BUFF_SIZE + 1];

	tp = *tmp;
	ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		tp = ft_strjoin(tp, buf);
		*tmp = tp;
		return (ret);
}

int	get_next_line(const int fd, char **line)
{
	static char *tmp = 0;
	static int cursor = 0;
	size_t k;
	int res;

	if (tmp == 0)
	{
		tmp = ft_strnew(BUFF_SIZE);
		if ((res = ft_read(fd, &tmp)) < 0)
			return (-1);
	}
	if (ft_read(fd, &tmp) == 0 && tmp[cursor] == '\0')
	{
		free(tmp);
		return (0);
	}
	k = 0;
	while (tmp[k + cursor] != '\n')
	{	
		if (tmp[k + cursor] != '\n' && tmp[k + cursor] == '\0')
			if ((res = ft_read(fd, &tmp)) < 0)
				return (-1);
		k++;
	/*ft_putstr("\n");
	ft_putstr(tmp + cursor);
	ft_putstr("  -->tmp boucle + cursor \n");
	*/
	}
	ft_putstr("\n");
	ft_putchar(tmp[k + cursor]);
	ft_putstr("  :tmp[k]\n");
	*line = ft_memalloc(k + 1);
	*line = ft_strncpy(*line, tmp + cursor, k);
	ft_putstr(*line);
	ft_putstr("  -->line\n");
	cursor += (k + 1);
	ft_putstr("\n");
	ft_putnbr(cursor);
	ft_putstr("  cursor after k + 1 \n");
	return (1);
}


