/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:53:41 by madufour          #+#    #+#             */
/*   Updated: 2019/01/10 12:17:47 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "get_next_line.h"

int		check_char(char *s, int nbl);
int		valid_tetris(char *s);
char	**tetriminos(char *s, int nbtetri);
int		solve(char *s, int nbl);
int		ft_algo(char *map, int sqr, char **tetri, int i);
char	*ft_resolve(int nbtetri, char **tetri, int *sq);
int		get_next_line(int fd, char **line);
int		split_tetri(char *s);
int		neighbour(int nb_l, char *s, int i, int *nb_d);
char	*ft_fill_tetri(char *s, char *tab, int *j, int c);
int		**ft_tab_coord(char *tetri);
int		ft_test_place(char *map, char *tetri, int sqr, int p);
void	ft_del(void ***p);
void	ft_del_main(char **line, char **str);

#endif
