/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:45:22 by brobson           #+#    #+#             */
/*   Updated: 2018/11/17 13:26:06 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * (ft_strlen((char*)s) + 1));
	if (str == NULL)
		return (NULL);
	while (*s)
	{
		str[i] = f(*s);
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
