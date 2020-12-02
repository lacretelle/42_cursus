NAME = megaphone
SRC =megaphone.cpp

CC = clang++
OBJ = $(SRC:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

.obj/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean 
