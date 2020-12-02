/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:36:08 by brobson           #+#    #+#             */
/*   Updated: 2018/11/17 10:32:24 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_abs(long int n)
{
	return ((n < 0) ? -n : n);
}

static size_t	nb_char(int n)
{
	int		cpt;

	cpt = 1;
	while (n /= 10)
		cpt++;
	return (cpt);
}

char			*ft_itoa(int n)
{
	int			len;
	char		*str;
	int			s;

	s = (n < 0) ? -1 : 1;
	len = nb_char(n);
	if (s == -1)
		len++;
	if (!(str = (char*)malloc((sizeof(char) * (len + 1)))))
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (s == -1)
		str[0] = '-';
	return (str);
}
