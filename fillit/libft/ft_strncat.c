/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:54:33 by brobson           #+#    #+#             */
/*   Updated: 2018/11/12 15:37:47 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	lend;
	size_t	i;

	i = 0;
	lend = 0;
	while (dest[lend] != '\0')
		lend++;
	while (i < n && src[i] != '\0')
	{
		dest[lend] = src[i];
		lend++;
		i++;
	}
	dest[lend] = '\0';
	return (dest);
}
