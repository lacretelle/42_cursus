/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:13:57 by madufour          #+#    #+#             */
/*   Updated: 2018/12/10 14:08:42 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		size_s1;
	int		size_s2;
	char	*res;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (!(res = (char*)malloc(sizeof(char) * (size_s1 + size_s2 + 1))))
		return (NULL);
	ft_strcpy(res, s1);
	ft_strdel(&s1);
	ft_strcat(res, s2);
	return (res);
}

int		ft_read(char **tp, int fd)
{
	int		res;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	tmp = 0;
	while ((res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[res] = '\0';
		if (!(*tp))
		{
			if (!(*tp = ft_strdup(buf)))
				return (-1);
		}
		else
		{
			if (!(tmp = ft_strjoin_free(*tp, buf)))
				return (-1);
			*tp = tmp;
		}
		if ((ft_strchr(buf, '\n')))
			return (res);
	}
	return (res);
}

char	*ft_cursor(char *tmp, int i)
{
	char	*s;

	s = 0;
	if (tmp[i] == '\n')
	{
		if (!(s = ft_strdup(tmp + i + 1)))
			return (NULL);
	}
	else if (tmp[i] == '\0')
	{
		if (!(s = ft_strnew(0)))
			return (NULL);
	}
	ft_strdel(&tmp);
	tmp = s;
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static char *tmp[10240];
	size_t		k;
	int			res;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = 0;
	if ((res = ft_read(&tmp[fd], fd)) < 0)
		return (-1);
	if (res == 0 && tmp[fd] == NULL)
		return (0);
	else if (res == 0 && tmp[fd][0] == '\0')
	{
		free(tmp[fd]);
		tmp[fd] = NULL;
		return (0);
	}
	k = 0;
	while (tmp[fd][k] != '\0' && tmp[fd][k] != '\n')
		k++;
	if (!(*line = ft_strsub(tmp[fd], 0, k)))
		return (-1);
	if (!(tmp[fd] = ft_cursor(tmp[fd], k)))
		return (-1);
	return (1);
}
