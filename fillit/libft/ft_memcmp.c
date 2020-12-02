/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:55:43 by brobson           #+#    #+#             */
/*   Updated: 2018/11/13 10:04:15 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptrs1;
	const unsigned char	*ptrs2;

	if (s1 == s2 || n == 0)
		return (0);
	ptrs1 = (const unsigned char*)s1;
	ptrs2 = (const unsigned char*)s2;
	while (n--)
	{
		if (*ptrs1 != *ptrs2)
			return (*ptrs1 - *ptrs2);
		if (n)
		{
			ptrs1++;
			ptrs2++;
		}
	}
	return (0);
}
