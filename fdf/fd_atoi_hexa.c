/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:40:10 by madufour          #+#    #+#             */
/*   Updated: 2019/03/02 17:01:24 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fd_check_map(char *s)
{
	int	i;

	i = 2;
	if (s[0] != '0')
		return (-1);
	if (s[1] != 'x')
		return (-1);
	while (s[i] != '\0')
	{
		if ((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 70)
				|| (s[i] >= 97 && s[i] <= 102))
			i++;
		else
			return (-1);
	}
	return (1);
}

int			fd_atoi_hexa(char *s)
{
	int		i;
	int		size;
	int		res;

	i = 0;
	res = 0;
	size = ft_strlen(s);
	if (size > 8 || size < 4 || fd_check_map(s) < 0)
		return (-1);
	i += 2;
	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'f')
			res = res + ((s[i] - 87) * ft_power(16, size - i - 1));
		else if (s[i] >= 'A' && s[i] <= 'F')
			res = res + ((s[i] - 55) * ft_power(16, size - i - 1));
		else
			res = res + ((s[i] - 48) * ft_power(16, size - i - 1));
		i++;
	}
	return (res);
}
