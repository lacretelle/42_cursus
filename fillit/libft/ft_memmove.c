/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:29:31 by brobson           #+#    #+#             */
/*   Updated: 2018/11/13 11:25:04 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char*)dest;
	s = (char*)src;
	i = -1;
	if (s < d)
	{
		while ((int)(--n) >= 0)
			*(d + n) = *(s + n);
	}
	else
	{
		while (++i < n)
			*(d + i) = *(s + i);
	}
	return (dest);
}
