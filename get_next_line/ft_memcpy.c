/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:58:56 by madufour          #+#    #+#             */
/*   Updated: 2018/11/26 13:43:57 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*str;

	i = 0;
	dest = (unsigned char*)dst;
	str = (unsigned char*)src;
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	return (dst);
}
