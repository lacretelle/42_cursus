/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:56:24 by madufour          #+#    #+#             */
/*   Updated: 2018/11/21 13:51:31 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int i;

	i = 0;
	if (s != 0)
	{
		while (s[i] != '\0')
		{
			s[i] = '\0';
			i++;
		}
	}
}