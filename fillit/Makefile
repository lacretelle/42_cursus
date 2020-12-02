# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madufour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 23:15:01 by madufour          #+#    #+#              #
#    Updated: 2019/01/10 10:18:16 by madufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = srcs/main.c srcs/check_char.c srcs/get_next_line.c srcs/valid_tetris.c \
	  srcs/solve.c srcs/ft_algo.c srcs/ft_resolve.c srcs/tetriminos.c \
	  srcs/ft_fill_tetri.c srcs/split_tetri.c srcs/ft_test_place.c \
	  srcs/neighbour.c srcs/ft_create_tabint.c srcs/ft_delete.c
HEADER = includes/fillit.h
LIB = -L. libft/libft.a
FLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIB)

clean:
		make clean -C libft/
		$(RM) $(OBJS)

fclean: clean
		make fclean -C libft/
		$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all re
