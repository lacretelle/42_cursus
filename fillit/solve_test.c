/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:24:42 by madufour          #+#    #+#             */
/*   Updated: 2018/12/12 17:42:22 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*solve_test(char *s, int map)
{
	char *res;
	int i;
	int j;

	i = 0;
	j = 0;
	res = ft_strnew((map * map) - 1);
	while (i < (map * map))
		res[i++] = '.';
	i = 0;
	while (res[i] != '\0')
	{
		if (map == 4)
		{
			while (s[j] != '\0')
			{
				if (s[j] != '.')
					res[i] = s[j];
				i++;
				j++;
			}
			return (res);
		}
		i++;
	}
	return (res);
}

int main()
{
	char s[16] = "AAA.A...........";
	int map = 4;
	char *res;

	if ((res = solve_test(s, map)))
		ft_putstr(res);
	return (0);
}
