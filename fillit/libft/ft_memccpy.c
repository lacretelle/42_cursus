/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:55:02 by brobson           #+#    #+#             */
/*   Updated: 2018/11/09 11:54:01 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*ptrd;
	const unsigned char	*ptrs;
	size_t				i;

	i = 0;
	ptrd = (unsigned char*)dest;
	ptrs = (const unsigned char*)src;
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		if (ptrs[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
