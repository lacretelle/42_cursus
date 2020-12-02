/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:10:35 by brobson           #+#    #+#             */
/*   Updated: 2018/11/13 10:12:41 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lend;
	size_t	i;
	size_t	lens;

	lend = ft_strlen((char*)dest);
	lens = ft_strlen((char*)src);
	i = 0;
	if (size <= lend)
		return (lens + size);
	while (dest[i] != '\0' && i < (size - 1))
		i++;
	while (i < size - 1 && *src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (lend + lens);
}
