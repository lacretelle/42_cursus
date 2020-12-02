/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:45:11 by brobson           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:00 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l;

	if (*little == '\0')
		return ((char*)big);
	l = ft_strlen((char*)little);
	while (*big != '\0' && len >= l)
	{
		if (*big == *little && ft_memcmp(big, little, l) == 0)
			return ((char*)big);
		big++;
		len--;
	}
	return (NULL);
}
