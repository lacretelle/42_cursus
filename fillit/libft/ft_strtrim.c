/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:51:58 by brobson           #+#    #+#             */
/*   Updated: 2018/11/16 14:00:04 by brobson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;

	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	len = ft_strlen((char*)s);
	while (*s && (s[len - 1] == ' ' || s[len - 1] == '\t' ||
				s[len - 1] == '\n'))
		len--;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_strncpy(str, s, len + 1);
	str[len] = '\0';
	return (str);
}
