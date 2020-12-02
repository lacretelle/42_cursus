/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:14:08 by madufour          #+#    #+#             */
/*   Updated: 2019/01/10 12:17:54 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_del(void ***p)
{
	int		i;
	void	**tab;

	i = 0;
	if ((p))
	{
		tab = *p;
		while (tab[i] != NULL)
		{
			ft_memdel(&tab[i]);
			i++;
		}
		free(tab);
		*p = NULL;
	}
}

void		ft_del_main(char **line, char **str)
{
	ft_strdel(str);
	ft_strdel(line);
}
