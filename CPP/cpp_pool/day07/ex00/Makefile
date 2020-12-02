NAME = whatever
SRC = main.cpp whatever.cpp

CC = clang++
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(SRC) $(INC) Makefile
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re:	fclean all

.PHONY: all clean fclean re
