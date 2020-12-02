# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madufour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/16 15:01:16 by madufour          #+#    #+#              #
#    Updated: 2019/03/18 15:19:02 by madufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c \
	  fl_init.c fl_user.c \
	  fl_mandelbrot.c fl_julia.c fl_burningship.c \
	  fl_draw.c fl_clear_img.c fl_color.c fl_color_psy.c \
	  fl_mouse.c fl_key.c fl_close.c

INC = -I . -I libft/

LIB = -L ./libft -lft -g -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJS = $(SRC:.c=.o)

LIBFT_NAME = ./libft/libft.a

HEAD = libft/libft.h fractol.h

CC = gcc

all: libft $(NAME)

libft:
	make -C libft/

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): Makefile $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB)

clean:
	make clean -C libft/
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all re libft
