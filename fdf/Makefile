# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madufour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 23:15:01 by madufour          #+#    #+#              #
#    Updated: 2019/03/02 16:50:34 by madufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c fd_read.c fd_modif_img.c fd_delete.c fd_draw_line.c fd_coord_iso.c \
	  	  fd_key_push.c fd_check.c fd_coord_para.c fd_color.c fd_init_conf.c fd_manage_hexa.c \
		  	  fd_win_base.c fd_deg_color.c fd_coord_euler.c fd_map_classic.c fd_atoi_hexa.c

INC = -I . -I libft/

LIB = -L ./libft -lft -g -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_NAME= libft/libft.a

OBJS = $(SRC:.c=.o)

HEAD = libft/libft.h fdf.h

CC = gcc

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_NAME) Makefile
		$(CC) $(FLAGS) -o $@ $(OBJS) $(LIB)

$(LIBFT_NAME): FORCE
		make -C libft/

%.o: %.c $(HEAD)
		$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
		make clean -C libft/
			$(RM) $(OBJS)

fclean: clean
		make fclean -C libft/
			$(RM) $(NAME)

re: fclean all

FORCE:

.PHONY: fclean clean all re
