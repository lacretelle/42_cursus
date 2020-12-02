/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:50:53 by brobson           #+#    #+#             */
/*   Updated: 2018/11/17 12:35:20 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen((char*)s);
	while ((len > 0) && (s[len] != (char)c))
		len--;
	if (s[len] == (char)c)
		return ((char*)&s[len]);
	return (NULL);
}
